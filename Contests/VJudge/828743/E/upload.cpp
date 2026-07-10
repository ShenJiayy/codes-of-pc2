#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 100;
bool f[N + 5][N + 5];
signed main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= n; j ++)
            cin >> f[i][j];
    for (int k = 1; k <= n; k ++)
        for (int i = 1; i <= n; i ++)
            for (int j = 1; j <= n; j ++)
                f[i][j] |= f[i][k] & f[k][j];
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= n; j ++)
            cout << f[i][j] << " ";
        cout << endl;
    }
    return 0;
}
