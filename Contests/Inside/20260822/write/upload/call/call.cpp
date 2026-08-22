#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e4, mod = 998244353;
int a[N + 5];
struct Node {
    int p, d;
    vector<int> child;
} dat[N + 5];
signed main() {
    freopen("call.in", "r", stdin);
    freopen("call.out", "w", stdout);
    int n, m, T;
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    cin >> m;
    for (int i = 1; i <= m; i ++) {
        int opt;
        cin >> opt;
        if (opt == 1) 
            cin >> dat[i].p >> dat[i].d, dat[i].child.push_back(i);
        else if (opt == 2) 
            cin >> dat[i].d, dat[i].p = 0, dat[i].child.push_back(i);
        else {
            int t;
            cin >> t;
            while (t --) {
                int idx;
                cin >> idx;
                for (int childs : dat[idx].child)
                    dat[i].child.push_back(childs);
            }
        }
    }
    cin >> T;
    while (T --) {
        int x;
        cin >> x;
        for (int todo : dat[x].child)
            if (dat[todo].p == 0)
                for (int i = 1; i <= n; i ++)
                    a[i] *= dat[todo].d, a[i] %= mod;
            else
                a[dat[todo].p] += dat[todo].d, a[dat[todo].p] %= mod;
    }
    for (int i = 1; i <= n; i ++)
        cout << a[i] << " ";
    return 0;
}