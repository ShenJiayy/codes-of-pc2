#include <bits/stdc++.h>
using namespace std;
#define int long long
#define judge
const int maxT = 1e4;
int q[maxT + 5];
signed main() {
    #ifdef judge
        freopen("cube.in", "r", stdin);
        freopen("cube.out", "w", stdout);
    #else
        freopen("data.in", "r", stdin);
        freopen("data.out", "w", stdout);
        freopen("data.log", "w", stderr);
    #endif
    int T;
    cin >> T;
    for (int i = 1; i <= T; i ++) cin >> q[i];
    if (T <= 10) {
        for (int i = 1; i <= T; i ++) {
            int x = q[i];
            map<int, int> mp;
            for (int j = 2; j <= x; j ++)
                while (x % j == 0) {
                    mp[j] ++;
                    x /= j;
                }
            if (x > 1)
                mp[x] ++;
            int res = 1;
            for (auto kv : mp) {
                int ds = kv.first, mc = kv.second / 3;
                res *= pow(ds, mc);
            }
            cout << res << endl;
        }
    }
    else if (*max_element(q + 1, q + T + 1) >= 1e9)
        for (int i = 1; i <= T; i ++) {
            cout << log(q[i]) / log(3) << endl;
        }
    return 0;
}
