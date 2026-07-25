#include <bits/stdc++.h>
using namespace std;
#define int long long
int fp(int a, int b, int p) {
    int ret = 1;
    for (; b; b >>= 1, a = a * a % p)
        if (b & 1)
            ret = ret * a % p;
    return ret;
}
const int mod = 998244353;
signed main() {
	queue<int> q;
    q.push(1);
    int ans = 1;
    int T;
    cin >> T;
    while (T --) {
        int opt;
        cin >> opt;
        if (opt == 1) {
            int x;
            cin >> x;
            ans *= 10;
            ans += x;
            ans %= mod;
            q.push(x);
            ans %= mod;
        }
        if (opt == 2) {
            int t = q.front();
            q.pop();
            ans -= t * fp(10, q.size(), mod);
            ans %= mod, ans += mod, ans %= mod;
        }
        if (opt == 3) 
            cout << ans << endl;
    }
    return 0;
}
