#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2500;
int n, m;
bool a[N + 5][N + 5], vis[N + 5][N + 5][2];
int ans;
void dfs(int x, int y) {
    int num = 1;
    if (vis[x][y][0] == 1) {
        int x1 = x, y1 = y;
        bool flg = 1;
        while (x1 <= n && y1 > 0 && flg) {
            x1 ++, y1 --;
            if (!a[x1][y1]) {
                flg = 0;
                break;
            }
            for (int i = x1 - 1; i >= x; i --)
                if (a[i][y1]) {
                    flg = 0;
                    for (int j = i + 1; j < x1; j ++)
                        vis[j][x1 + y1 - j][0] = 0;
                    break;
                }
            for (int j = y1 + 1; j <= y; j ++)
                if (a[x1][j]) {
                    flg = 0;
                    for (int i = j - 1; i > y1; i --)
                        vis[x1 + y1 - i][i][0] = 0;
                    break;
                }
            if (!flg)
                break;
            num ++;
            vis[x1][y1][0] = 1;
        }
    }
    ans = max(ans, num);
    num = 1;
    if (vis[x][y][0] == 1) {
        int x1 = x, y1 = y;
        bool flg = 1;
        while (x1 <= n && y1 <= m && flg) {
            x1 ++, y1 ++;
            if (!a[x1][y1]) {
                flg = 0;
                break;
            }
            for (int i = x1 - 1; i >= x; i --)
                if (a[i][y1]) {
                    flg = 0;
                    for (int j = i + 1; j < x1; j ++)
                        vis[j][x1 + y1 - j][0] = 0;
                    break;
                }
            for (int j = y1 - 1; j >= y; j --)
                if (a[x1][j]) {
                    flg = 0;
                    for (int i = j + 1; i < y1; i ++)
                        vis[x1 + y1 - i][i][0] = 0;
                    break;
                }
            if (!flg)
                break;
            num ++;
            vis[x1][y1][0] = 1;
        }
    }
    ans = max(ans, num);
}
signed main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++)
            cin >> a[i][j];
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++)
            if (a[i][j])
                dfs(i, j);
    cout << ans;
    return 0;
}