#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 100, BIGINT = 0x3f3f3f3f3f3f3f3f;
int dis[N + 5][N + 5];

signed main() {
    #ifndef ONLINE_JUDGE
        freopen("in.in", "r", stdin);
    #endif
    int n, m;
    cin >> n >> m;
    memset(dis, 0x3f, sizeof dis);
    for (int i = 1; i <= m; i ++) {
        int a, b, c;
        cin >> a >> b >> c;
        dis[a][b] = dis[b][a] = c;
    }
    for (int i = 1; i <= n; i ++)
        dis[i][i] = 0;
    for (int k = 1; k <= n; k ++)
        for (int i = 1; i <= n; i ++)
            for (int j = 1; j <= n; j ++)
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
    int ans = 0;
    for (int i = 1; i <= n; i ++)
        ans = max(ans, dis[1][i]);
    if (ans >= BIGINT)
        cout << -1;
    else
        cout << ans;
    return 0;
}