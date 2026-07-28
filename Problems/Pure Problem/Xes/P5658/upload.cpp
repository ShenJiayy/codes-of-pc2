#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2000;
char s[N + 5];
vector<int> g[N + 5];
int ans = 0, k[N + 5];
set<string> box;
void dfs(int id, int ft, string res) {
    res += s[id];
    box.clear();
    for (int i = 0; i < res.size(); i ++) {
        int cnt = 0;
        string now = "";
        for (int j = i; j < res.size(); j ++) {
            now += res[j];
            if (res[j] == '(') cnt ++;
            else cnt --;
            if (cnt < 0)
                break;
            if (box.count(now)) continue;
            box.insert(now);
            if (cnt == 0)
                k[id] ++;
        }
    }
    ans ^= id * k[id];
    for (int nxt : g[id])
        if (nxt != ft)
            dfs(nxt, id, res);
}
signed main() {
	int n;
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> s[i];
    for (int i = 2; i <= n; i ++) {
        int f;
        cin >> f;
        g[f].push_back(i);
        g[i].push_back(f);
    }
    dfs(1, 0, "");
    cout << ans;
    return 0;
}
