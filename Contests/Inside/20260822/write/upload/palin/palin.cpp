#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 20;
int a[N * 2 + 5], n;
bool vis[N * 2 + 5];
string ans;
void dfs(int id) {
    if (id > n) {
        int l = 1, r = n;
        vector<int> res;
        for (int i = 1; i <= n; i ++)
            if (vis[i]) {
                res.push_back(a[l]);
                l ++;
            }
            else {
                res.push_back(a[r]);
                r --;
            }
        l = 0, r = n - 1;
        while (l <= r) {
            if (res[l] != res[r])
                return ;
            l ++, r --;
        }
        string now;
        for (int i = 1; i <= n; i ++)
            if (vis[i])
                now += 'L';
            else now += 'R';
        if (now < ans)
            ans = now;
        return ;
    }
    vis[id] = 0;
    dfs(id + 1);
    vis[id] = 1;
    dfs(id + 1);
}
signed solve() {
    cin >> n;
    n *= 2;
    ans = "";
    for (int i = 1; i <= n; i ++)
        cin >> a[i], ans += 'R';
    dfs(1);
    if (ans.find('L') == string::npos)
        puts("-1");
    else cout << ans << endl;
    return 0;
}
signed main() {
    freopen("palin.in", "r", stdin);
    freopen("palin.out", "w", stdout);
    int T;
    cin >> T;
    while (T --) 
        solve();
    return 0;
}