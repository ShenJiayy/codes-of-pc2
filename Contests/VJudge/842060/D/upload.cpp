#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e7;
int cc[N + 5];
int gcd(int x, int y) {
    if (y == 0)
        return x;
    return gcd(y, x % y);
}
signed main() {
    for (int i = 1; i <= N; i ++)
        for (int j = 1; i * j <= N; j ++)
            cc[i * j] ++;
    int T;
    cin >> T;
    while (T --) {
        int x, y;
        cin >> x >> y;
        int gx = gcd(x, y);
        int gs = gcd(gx, (x + y) >> 1);
        if (x + y & 1)
            cout << cc[gx];
        else cout << cc[gx] - cc[gs];
        cout << endl;
    }
    return 0;
}