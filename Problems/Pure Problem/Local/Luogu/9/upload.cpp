#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 60, dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
char a[N + 5][N + 5];
int n, dist[N + 5][N + 5][N + 5][N + 5];
struct Node {
    int x, y, z, u;
};
inline bool valid(int x, int y) {
    return 1 <= x && x <= n && 1 <= y && y <= n && a[x][y] != '#';
}
void bfs(Node st) {
    queue<Node> q;
    q.push(st);
    memset(dist, 0x3f, sizeof dist);
    dist[st.x][st.y][st.z][st.u] = 0;
    while (!q.empty()) {
        auto [x, y, z, u] = q.front();
        q.pop();
        if (x == z && y == u) {
            cout << dist[x][y][z][u];
            exit(0);
        }
        for (int k = 0; k < 4; k ++) {
            int nx = x + dx[k], ny = y + dy[k],
                nz = z + dx[k], nu = u + dy[k];
            if (!valid(nx, ny)) nx = x, ny = y;
            if (!valid(nz, nu)) nz = z, nu = u;
            if (dist[nx][ny][nz][nu] > dist[x][y][z][u] + 1)
                dist[nx][ny][nz][nu] = dist[x][y][z][u] + 1,
                q.push({nx, ny, nz, nu});
        }
    }
}
signed main() {
    vector<pair<int, int>> ps;
    cin >> n;
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= n; j ++) {
            cin >> a[i][j];
            if (a[i][j] == 'P')
                ps.push_back({i, j});
        }
    bfs({ps[0].first, ps[0].second, ps[1].first, ps[1].second});
    puts("-1");
    return 0;
}
