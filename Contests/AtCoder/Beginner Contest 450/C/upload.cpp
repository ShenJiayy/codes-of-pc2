#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e3, dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
int n, m;
bool black[N + 5][N + 5], vis[N + 5][N + 5];
bool dfs(int i, int j) {
    if (vis[i][j]) return 1;
    if (black[i][j]) return 1;
    if ((i == 1 || i == n || j == 1 || j == m)) return 0;
    if (!(1 < i && i < n && 1 < j && j < m)) return 1;
    vis[i][j] = 1;
    bool flg = 1;
    for (int d = 0; d < 4; d ++)
        flg = flg & dfs(i + dx[d], j + dy[d]);
    return flg;
}
signed main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++) {
            char c;
            cin >> c;
            black[i][j] = c == '#';
        }
    int cnt = 0;
    for (int i = 2; i < n; i ++)
        for (int j = 2; j < m; j ++)
            if (!vis[i][j] && black[i][j] == 0)
                cnt += dfs(i, j);
    cout << cnt;
    return 0;
}