#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1000;
int p[N + 5][N + 5], n, m;
bool vis[N + 5][N + 5];
const int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
bool check(int mid) {
    memset(vis, 0, sizeof vis);
    queue<pair<int, int>> q;
    q.push({1, 1});
    vis[1][1] = 1;
    while (!q.empty()) {
        auto [tx, ty] = q.front();
        q.pop();
        if (tx == n) return 1;
        for (int k = 0; k < 4; k ++) {
            int nx = tx + dx[k], ny = ty + dy[k];
            if (!(1 <= nx && nx <= n && 1 <= ny && ny <= m)) continue;
            if (p[nx][ny] > mid) continue;
            if (vis[nx][ny]) continue;
            q.push({nx, ny});
            vis[nx][ny] = 1;
        }
    }
    return 0;
}
signed main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++)
            cin >> p[i][j];
    int ans = -1, l = 1, r = N;
    while (l <= r) {
        int mid = l + r >> 1;
        if (check(mid))
            ans = mid, r = mid - 1;
        else l = mid + 1;
    }
    cout << ans;
    return 0;
}
