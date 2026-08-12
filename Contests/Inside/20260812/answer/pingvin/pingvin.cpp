#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 100;
bool able[N + 5][N + 5][N + 5], vis[N + 5][N + 5][N + 5];
int dis[N + 5][N + 5][N + 5];
const int dx[] = {0, 0, 0, 0, 1, -1};
const int dy[] = {0, 0, 1, -1, 0, 0};
const int dz[] = {1, -1, 0, 0, 0, 0};
struct Pos {
    int x, y, z;
};
signed main() {
    freopen("pingvin.in", "r", stdin);
    freopen("pingvin.out", "w", stdout);
    int n;
    cin >> n;
    Pos st, ed;
    cin >> st.x >> st.y >> st.z >> ed.x >> ed.y >> ed.z;
    queue<Pos> q;
    q.push(st);
    memset(dis, 0x3f, sizeof dis);
    dis[st.x][st.y][st.z] = 0;
    for (int k = 1; k <= n; k ++)
        for (int i = 1; i <= n; i ++)
            for (int j = 1; j <= n; j ++) {
                char c;
                cin >> c;
                able[i][j][k] = c - '0';
            }
    while (!q.empty()) {
        Pos t = q.front();
        q.pop();
        if (vis[t.x][t.y][t.z]) continue;
        if (able[t.x][t.y][t.z] == 1) continue;
        if (!(1 <= t.x && t.x <= n && 1 <= t.y && t.y <= n && 1 <= t.z && t.z <= n))
            continue;
        vis[t.x][t.y][t.z] = 1;
        for (int i = 0; i < 6; i ++) {
            Pos n = {t.x + dx[i], t.y + dy[i], t.z + dz[i]};
            q.push(n);
            if (able[n.x][n.y][n.z] == 0) 
                dis[n.x][n.y][n.z] = min(dis[n.x][n.y][n.z], dis[t.x][t.y][t.z] + 1);
        }
    }
    if (dis[ed.x][ed.y][ed.z] > 2500)
        return puts("-1"), 0;
    cout << dis[ed.x][ed.y][ed.z];
    return 0;
}