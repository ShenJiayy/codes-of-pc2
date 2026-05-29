#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pic pair<int, char>
const int N = 1e6;
char ans[N + 5];
int cnt[128];
void solve() {
    memset(cnt, 0, sizeof cnt);
    string s;
    cin >> s;
    int n = s.size();
    vector<pic> box;
    for (char c : s)
        cnt[c] ++;
    for (char c = 'a'; c <= 'z'; c ++)
        if (cnt[c])
            box.push_back(pic(cnt[c], c));
    sort(box.begin(), box.end());
    if (box.back().first > (n + 1) / 2) {
        printf("No\n"); return ;
    }
    printf("Yes\n");
    for (int i = 1; i <= n; i += 2) {
        ans[i] = box.back().second;
        if (-- box.back().first == 0)
            box.pop_back();
    }
    for (int i = 2; i <= n; i += 2) {
        ans[i] = box.back().second;
        if (-- box.back().first == 0)
            box.pop_back();
    }
    printf("%s\n", ans + 1);
}
signed main() {
	int T;
    cin >> T;
    while (T --) 
        solve();
    return 0;
}