#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int l, c, q;
    cin >> l >> c >> q;
    while (q --) {
        int opt, x;
        cin >> opt >> x;
        if (opt == 1) {
            cout << c * x;
            l -= x;
        }
        else {
            cout << l * x;
            c -= x;
        }
        cout << endl;
    }
    return 0;
}