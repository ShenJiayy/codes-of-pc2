#include <bits/stdc++.h>
using namespace std;
#define int long long
#define local

signed main() {
    #ifdef local
        freopen("./sample/2/in.in", "r", stdin);
    #endif
    int p, q, i, j;
    cin >> p >> q >> i >> j;
    int sx = p, sy = q;
    int ex = p + 99, ey = q + 99;
    if (sx <= i && i <= ex && sy <= j && j <= ey)
        cout << "Yes";
    else
        cout << "No";
    return 0;
}