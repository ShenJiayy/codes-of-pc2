#include <bits/stdc++.h>
using namespace std;
#define int long long

const int STATUS_MAX = 1 << 10, N_MAX = 10, M_MAX = 100, INF = 0x3f3f3f3f3f3f3f3f;
int a[M_MAX + 5], b[M_MAX + 5];
int f[STATUS_MAX + 5];
bool vis[STATUS_MAX + 5];

signed main() {
    #ifndef ONLINE_JUDGE
        freopen("in.in", "r", stdin);
    #endif
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i ++)
        for (int j = 1; j <= n; j ++) {
            int x;
            cin >> x;
            if (x == 1) 
                a[i] |= (1 << j - 1);
            if (x == -1) 
                b[i] |= (1 << j - 1);
        }
    queue<int> q;
    q.push(0);
    memset(f, 0x3f, sizeof f);
    f[0] = 0;
    while (!q.empty()) {
        int t = q.front();
        q.pop();
        vis[t] = 0;
        for (int i = 1; i <= m; i ++) {
            int state = (t | a[i]) & (~b[i]);
            if (f[state] > f[t] + 1) {
                f[state] = f[t] + 1;
                if (!vis[state])
                    q.push(state), vis[state] = 1;
            }
        }
    }
    int ans = f[(1 << n) - 1];
    if (ans == INF)
        cout << -1;
    else
        cout << ans;
    return 0;
}