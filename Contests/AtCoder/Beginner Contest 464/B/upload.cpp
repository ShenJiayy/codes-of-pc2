#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 50;
char c[N + 5][N + 5];
signed main() {
	int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++)
            cin >> c[i][j];
    int u = 1, d = n, l = 1, r = m;
    while (1) {
        bool valid = 1;
        for (int i = 1; i <= m; i ++)
            if (c[u][i] == '#') valid = 0;
        if (valid) u ++;
        else break; 
    }
    while (1) {
        bool valid = 1;
        for (int i = 1; i <= m; i ++)
            if (c[d][i] == '#') valid = 0;
        if (valid) d --;
        else break; 
    }
    while (1) {
        bool valid = 1;
        for (int i = 1; i <= n; i ++)
            if (c[i][l] == '#') valid = 0;
        if (valid) l ++;
        else break; 
    }
    while (1) {
        bool valid = 1;
        for (int i = 1; i <= n; i ++)
            if (c[i][r] == '#') valid = 0;
        if (valid) r --;
        else break; 
    }
    for (int i = u; i <= d; i ++) {
        for (int j = l; j <= r; j ++)
            cout << c[i][j];
        cout << endl;
    }
    return 0;
}
