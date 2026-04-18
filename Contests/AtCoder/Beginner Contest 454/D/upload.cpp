#include <bits/stdc++.h>
using namespace std;
#define int long long
// inline string go(string a) {
//     for (int i = 0; i + 3 < a.size(); i ++) {
//         if (a[i] == '(' && a[i + 1] == 'x' && a[i + 2] == 'x' && a[i + 3] == ')')
//             a[i] = a[i + 3] = 0, i += 3;
//     }
//     string ca;
//     for (int i = 0; i < a.size(); i ++)
//         if (a[i])
//             ca += a[i];
//     return ca;
// }

string go(string a, int l, int r) {
    string res;
    for (int i = l; i < r; i ++) {
        if (a[i] == 'x') res += 'x';
        if (a[i] == '(') {
            int e = a.find(')', i + 1);
            if (e != -1)
                res += go(a, i + 1, e), i = e;
            else res += ')';
        }
        if (a[i] == ')')
            res += ')';
    }
    return res;
}
signed main() {
    int T;
    cin >> T;
    while (T --) {
        string a, b;
        cin >> a >> b;
        // while (1) {
        //     string p = go(a);
        //     if (p == a) break;
        //     a = p;
        // }
        // while (1) {
        //     string p = go(b);
        //     if (p == b) break;
        //     b = p;
        // }
        a = go(a, 0, a.size());
        b = go(b, 0, b.size());
        cout << a << " " << b << endl;
        if (a == b)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}