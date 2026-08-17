#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 50;
char c[N + 5][N + 5];
int min(int a, int b, int c, int d) {
    return min(min(a, b), min(c, d));
}
int min(int a, int b, int c, int d, int e, int f, int g, int h) {
    return min(min(a, b, c, d), min(e, f, g, h));
}
signed main() {
    freopen("pahuljice.in", "r", stdin);
    freopen("pahuljice.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++)
            cin >> c[i][j];
    int ans = 0;
    for (int x = 1; x <= n; x ++)
        for (int y = 1; y <= m; y ++) {
            if (c[x][y] != '+')
                continue ;
            int dnx = 0, dpx = 0;
            // To Left
            for (int i = y - 1; i >= 1; i --)
                if (c[x][i] == '-')
                    dnx ++;
                else 
                    break;
            // To Right
            for (int i = y + 1; i <= m; i ++)
                if (c[x][i] == '-')
                    dpx ++;
                else 
                    break;
            // To Bottom
            int dny = 0, dpy = 0;
            for (int i = x - 1; i >= 1; i --)
                if (c[i][y] == '|')
                    dny ++;
                else 
                    break;
            // To Top
            for (int i = x + 1; i <= n; i ++)
                if (c[i][y] == '|')
                    dpy ++;
                else 
                    break;
            // Top Left
            int tl = 0, tr = 0, bl = 0, br = 0;
            for (int i = x - 1, j = y - 1; i >= 1 && j >= 1; i --, j --)
                if (c[i][j] == '\\')
                    tl ++;
                else 
                    break;
            // Top Right
            for (int i = x - 1, j = y + 1; i >= 1 && j <= m; i --, j ++)
                if (c[i][j] == '/')
                    tr ++;
                else 
                    break;
            // Bottom Left
            for (int i = x + 1, j = y - 1; i <= n && j >= 1; i ++, j --)
                if (c[i][j] == '/')
                    bl ++;
                else 
                    break;
            // Bottom Right
            for (int i = x + 1, j = y + 1; i <= n && j <= m; i ++, j ++)
                if (c[i][j] == '\\')
                    br ++;
                else 
                    break;
            ans = max(ans, min(dpx, dnx, dpy, dny, tl, tr, bl, br));
        }
    cout << ans;
    return 0;
} 