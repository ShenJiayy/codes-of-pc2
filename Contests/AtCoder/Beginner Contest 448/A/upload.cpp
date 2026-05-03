#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int n, x;
    cin >> n >> x;
    for (int i = 1; i <= n; i ++) {
        int pt;
        cin >> pt;
        if (pt < x) {
            cout << 1;
            x = pt;
        }
        else cout << 0;
        cout << endl;
    }
    return 0;
}