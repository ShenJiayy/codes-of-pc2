#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 100;
char c1[N + 5][N + 5], c2[N + 5][N + 5];
bool box[128];
signed main() {
    freopen("labirint.in", "r", stdin);
    freopen("labirint.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j < m; j ++)
            cin >> c1[i][j];
    for (int i = 1; i < n; i ++)
        for (int j = 1; j <= m; j ++)
            cin >> c2[i][j];
    int T;
    cin >> T;
    if (n == 1) { // Subtask 1
        while (T --) {
            int _, x, y;
            cin >> _ >> x >> _ >> y;
            if (x > y) swap(x, y);
            memset(box, 0, sizeof box);
            for (int i = x; i < y; i ++)
                box[c1[1][i]] ++;
            int cnt = box['P'] + box['C'] + box['Z'] + box['N'];
            cout << cnt << endl;
        }
    }
    else { // Subtask 2
        while (T --) {
            int x, y, xx, yy;
            cin >> x >> y >> xx >> yy;
            int cnt = 0;
            if (x != xx) cnt ++;
            if (y != yy) cnt ++;
            cout << cnt << endl;
        }
    }
    return 0;
}