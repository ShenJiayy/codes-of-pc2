#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 500;
int a[N + 5][N + 5];
bool vis[N + 5][N + 5];
const int dx[] = {0, 1, 0, 1}, dy[] = {0, 0, 1, 1};
signed main() {
    freopen("mask.in", "r", stdin);
    freopen("mask.out", "w", stdout);
    int n, m, T;
    cin >> n >> m >> T;
    while (T --) {
        int opt, x, y;
        cin >> opt >> x >> y;
        if (opt == 1) {
            int c;
            cin >> c;
            for (int i = 0; i < 4; i ++)
                if (!vis[x + dx[i]][y + dy[i]])
                    a[x + dx[i]][y + dy[i]] = c;
        }
        else 
            for (int i = 0; i < 4; i ++)
                vis[x + dx[i]][y + dy[i]] = 1;
    }
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++)
            cout << a[i][j] << " ";
        cout << endl;
    }
    return 0;
}