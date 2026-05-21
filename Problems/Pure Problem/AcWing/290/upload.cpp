#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1000;
double f[N + 5][N + 5], a[N + 5][N + 5];
int n, m, x, y;
inline void gauss() {
    for (int i = 1; i <= m; i ++) {
        // f[i][j]
        double fir = a[i][i];
        a[i][i] /= fir, 
        a[i][i + 1] /= fir;
        if (i < m) a[i][m + 1] /= fir;
        double scd = a[i + 1][i];
        int dx[] = {i, i + 1, m + 1};
        for (int j = 0; j < 3; j ++)
            a[i + 1][dx[j]] -= scd * a[i][dx[j]];
    }
    for (int i = m; i; i --) {
        a[i - 1][m + 1] -= a[i - 1][i] * a[i][m + 1];
        a[i - 1][i] = 0;
    }
}
signed main() {
    cin >> n >> m >> x >> y;
    if (m == 1) {
        printf("%.4lf", 2.0 * (n - x));
        return 0;
    }
    for (int i = n - 1; i >= x; i --) {
        a[1][1] = 2.0 / 3, 
        a[1][2] = -1.0 / 3,
        a[1][m + 1] = f[i + 1][1] / 3 + 1,
        a[m][m] = 2.0 / 3,
        a[m][m - 1] = -1.0 / 3,
        a[m][m + 1] = f[i + 1][m] / 3 + 1;
        for (int j = 2; j < m; j ++)
            a[j][j - 1] = -0.25,
            a[j][j] = 0.75,
            a[j][j + 1] = -0.25,
            a[j][m + 1] = f[i + 1][j] / 4 + 1;  
        gauss();
        for (int j = 1; j <= m; j ++)
            f[i][j] = a[j][m + 1];
    }
    printf("%.4lf", f[x][y]);
    return 0;
}