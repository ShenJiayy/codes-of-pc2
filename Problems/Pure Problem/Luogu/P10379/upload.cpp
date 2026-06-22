#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 500, dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
int a[N + 5][N + 5], n, m;
int col[N + 5][N + 5], nc;
set<pair<int, int>> belong[N * N + 5], vals[N * N + 5];
void dfs(int x, int y) {
    if (!(1 <= x && x <= n && 1 <= y && y <= m)) return;
    if (col[x][y]) return ;
    col[x][y] = nc;
    belong[nc].insert({x, y});
    for (int i = 0; i < 4; i ++) 
        if (a[x][y] == a[x + dx[i]][y + dy[i]])
            dfs(x + dx[i], y + dy[i]);
}
signed main() {
	cin >> n >> m;
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++)
            cin >> a[i][j];
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++)
            if (col[i][j] == 0) {
                nc ++;
                dfs(i, j);
            }
    for (int i = 1; i <= nc; i ++) {
        pair<int, int> lu = *belong[i].begin();
        for (pair<int, int> p : belong[i])
            vals[i].insert({p.first - lu.first, p.second - lu.second});
    }
    set<set<pair<int, int>>> box;
    for (int i = 1; i <= nc; i ++)
        box.insert(vals[i]);
    cout << box.size();
    return 0;
}