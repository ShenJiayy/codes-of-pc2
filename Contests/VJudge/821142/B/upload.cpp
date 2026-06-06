#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
const int N = 1e6;
const int dx[] = {1, 0, -1, 0, 1, 1, -1, -1};
const int dy[] = {0, 1, 0, -1, 1, -1, 1, -1};
vector<char> a[N + 5], b[N + 5];
vector<int> dis[N + 5];
signed main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) {
        a[i].resize(m + 5), b[i].resize(m + 5);
        for (int j = 1; j <= m; j ++)
            cin >> a[i][j];
    }
    for (int i = 1; i <= n; i ++) {
        dis[i].resize(m + 5);
        for (int j = 1; j <= m; j ++) {
            dis[i][j] = 9e18;
            if (a[i][j] == '#')
                for (int k = 0; k < 8; k ++) {
                    int x = i + dx[k], y = j + dy[k];
                    if (x < 1 || x > n || y < 1 || y > m)
                        continue;
                    if (a[x][y] == '.') 
                        b[x][y] = '#';
                    else b[x][y] = '.';
                }
        }
    }
    queue<pii> q;
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++)
            if (b[i][j] == '#')
                q.emplace(pii(i, j)), dis[i][j] = 0;
    while (!q.empty()) {
        pii t = q.front();
        q.pop();
        for (int k = 0; k < 8; k ++) {
            int nx = t.first + dx[k], ny = t.second + dy[k];
            if (!(1 <= nx && nx <= n && 1 <= ny && ny <= m) || dis[nx][ny] != 9e18)
                continue;
            dis[nx][ny] = dis[t.first][t.second] + 1;
            q.emplace(pii(nx, ny));
        }
    }
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++)
            if (dis[i][j] & 1)
                cout << '#';
            else cout << '.';
        cout << endl;
    }
    return 0;
}