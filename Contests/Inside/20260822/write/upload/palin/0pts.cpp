#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 20;
int a[N * 2 + 5], n;
bool vis[N * 2 + 5];
deque<int> q;
char ans[N * 2 + 5], inv[128];
bool dfs(int ll, int lr, int rl, int rr, char now) {
    if (ll == lr + 1 || rl == rr + 1)
        return 1;
    q.clear();
    for (int i = ll; i <= n; i ++)
        q.push_back(a[i]);
    for (int i = rl; i <= 2 * n; i ++)
        q.push_back(a[i]);
    int dis = lr - ll + 1;
    for (int i = 1; i <= dis; i ++) {
        if (q[1] == q[dis + 1]) 
            return dfs(ll + 1, lr, rl + 1, rr, inv[now]);
        ans[ll + i - 1] = ans[rr - i + 1] = now;
    }
    return 0;
}
signed solve() {
    cin >> n;
    for (int i = 1; i <= n * 2; i ++)
        cin >> a[i];
    bool ret = dfs(1, n, n + 1, 2 * n, 'L');
    if (ret)
        puts(ans + 1);
    else puts("-1");
    return 0;
}
signed main() {
    freopen("palin.in", "r", stdin);
    freopen("palin.out", "w", stdout);
    inv['L'] = 'R';
    inv['R'] = 'L';
    int T;
    cin >> T;
    while (T --) 
        solve();
    return 0;
}