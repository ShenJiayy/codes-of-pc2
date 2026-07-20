#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e4;
int fp(int a, int b, int p) {
    int ret = 1;
    for (; b; a = a * a % p, b >>= 1)
        if (b & 1)
            ret = ret * a % p;
    return ret;
}
signed main() {
	int n;
    cin >> n;
    int s = 0;
    for (int pw = 1, bt = 1; pw <= n; pw *= 10, bt ++)
        s += (min(pw * 10 - 1, n) - pw + 1) * bt;
    cout << ((((s + n + 2) % mod * fp(2, n - 1, mod) % mod + s) % mod + 3 * n % mod) % mod - 4 + mod) % mod;
    return 0;
}
