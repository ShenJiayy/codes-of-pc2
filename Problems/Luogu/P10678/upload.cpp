#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5;
int d[N + 5];
bool g[N + 5][N + 5];
void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> d[i];
    // 于是我们每次给树连边只需要拿一个剩余需连的边数为 1 的点和剩余需连的边数大于 1 的点相连即可，注意，如果没有剩余需连的边数大于 1 的点，需要特判，让另一个度数为 1 的点与这个点相连。
    memset(g, 0, sizeof g);
    for (int i = 1; i <= n; i ++) {
        bool hasres = 0;
        for (int j = 1; j <= n; j ++)
            if (d[j] > 1) {
                hasres = 1;
                bool hasans = 0;
                for (int k = 1; k <= n; k ++)
                    if (d[k] == 1) {
                        g[j][k] = g[k][j] = 1;
                        d[j] --, d[k] --;
                        hasans = 1;
                        break;
                    }
                if (hasans == 1) break;
            }
        if (hasres == 0)
            for (int j = 1; j <= n; j ++)
                if (d[j] == 1)
                    for (int k = 1; k <= n; k ++)
                        if (d[k] == 1)
                            g[j][k] = g[k][j] = 1, \
                            d[j] --, d[k] --;
    }
    for (int i = 1; i <= n; i ++)
        for (int j = i + 1; j <= n; j ++)
            if (g[i][j])
                cout << i << " " << j << endl;
}
signed main() {
	int T;
    cin >> T;
    while (T --) 
        solve();
    return 0;
}