#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int t, x, d;
    cin >> t >> x >> d;
    cout << "0 " << d << endl;
    for (int i = 1; i <= t; i ++) {
        int p;
        cin >> p;
        if (abs(p - d) >= x) {
            d = p;
            cout << i << " " << d << endl;
        }
    }
    return 0;
}