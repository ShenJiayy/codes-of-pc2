#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 100;
int c[N + 5][N + 5];
signed main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++)
        for (int j = i + 1; j <= n; j ++)
            cin >> c[i][j];
    bool flg = 0;
    for (int i = 1; i <= n; i ++)
        for (int j = i; j <= n; j ++)
            for (int k = j; k <= n; k ++)
                if (c[i][j] + c[j][k] < c[i][k])
                    flg = 1;
    if (flg) cout << "Yes";
    else cout << "No";
    return 0;
}