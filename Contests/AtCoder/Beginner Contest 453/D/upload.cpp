#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1000;
int n, m;
char c[N + 5][N + 5];
bool vis[N + 5][N + 5];
struct status {
    int x, y, k;
} from[N + 5][N + 5][4];
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
const char opt[] = {'D', 'U', 'R', 'L'};
int dis[N + 5][N + 5][4];
void print(int i, int j, int k) {
    if (c[i][j] == 'S') return ;
    print(from[i][j][k].x, from[i][j][k].y, from[i][j][k].k);
    cout << opt[k];
}
void bfs(int i, int j, int kk) {
    queue<status> q;
    q.push({i, j, kk});
    memset(vis, 0, sizeof vis);
    memset(dis, 0x1f, sizeof dis);
    vis[i][j] = 1;
    dis[i][j][kk] = 1;
    while (!q.empty()) {
        status t = q.front();
        q.pop();
//        if (dis[t.x + dx[t.k]][t.y + dy[t.k]][t.k] > 5e6) return ;
//        if (vis[t.x][t.y]) continue;
//        vis[t.x][t.y] = 1;
        cerr << t.x << t.y << t.k << endl;
        if (c[t.x][t.y] == 'G') {
            cout << "Yes\n";
            print(t.x, t.y, t.k);
            exit(0);
        }
        if (c[t.x][t.y] == '#') continue;
        if (c[t.x][t.y] == 'o') {
            if (dis[t.x + dx[t.k]][t.y + dy[t.k]][t.k] > dis[t.x][t.y][t.k] + 1)
                dis[t.x + dx[t.k]][t.y + dy[t.k]][t.k] = dis[t.x][t.y][t.k] + 1, from[t.x + dx[t.k]][t.y + dy[t.k]][t.k] = {t.x, t.y, t.k}, q.push({t.x + dx[t.k], t.y + dy[t.k], t.k});
        }
        if (c[t.x][t.y] == 'x') {
            for (int l = 0; l < 4; l ++)
                if (l != t.k)
                    if (dis[t.x + dx[l]][t.y + dy[l]][l] > dis[t.x][t.y][t.k] + 1)
                        dis[t.x + dx[l]][t.y + dy[l]][l] = dis[t.x][t.y][t.k] + 1, from[t.x + dx[l]][t.y + dy[l]][l] = {t.x, t.y, t.k}, q.push({t.x + dx[l], t.y + dy[l], l});
        }
        if (c[t.x][t.y] == '.' || c[t.x][t.y] == 'S') {
            for (int l = 0; l < 4; l ++)
                if (dis[t.x + dx[l]][t.y + dy[l]][l] > dis[t.x][t.y][t.k] + 1)
                    dis[t.x + dx[l]][t.y + dy[l]][l] = dis[t.x][t.y][t.k] + 1, from[t.x + dx[l]][t.y + dy[l]][l] = {t.x, t.y, t.k}, q.push({t.x + dx[l], t.y + dy[l], l});
        }
    }
}
signed main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++)
            cin >> c[i][j];
    pair<int, int> st, ed;
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++)
            if (c[i][j] == 'S')
                st = {i, j};
            else if (c[i][j] == 'G')
                ed = {i, j};
    for (int k = 0; k < 4; k ++)
        bfs(st.first, st.second, k);
    cout << "No";
    return 0;
}
