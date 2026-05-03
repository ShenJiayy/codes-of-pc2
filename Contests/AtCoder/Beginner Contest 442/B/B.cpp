#include <bits/stdc++.h>
using namespace std;
#define int long long
#define local

signed main() {
    #ifdef local
        freopen("in.in", "r", stdin);
    #endif
    int q, vol = 0;
    bool ply = 0;
    cin >> q;
    while (q --) {
        int op;
        cin >> op;
        if (op == 1)
            vol ++;
        if (op == 2 && vol)
            vol --;
        if (op == 3)
            ply = !ply;
        if (ply && vol >= 3)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}