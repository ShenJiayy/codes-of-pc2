#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5, mod = 998244353;
int a[N + 5], mul[N + 5];
int fp(int a, int b, int p) {
    int ret = 1;
    for (; b; b >>= 1, a = a * a % p)
        if (b & 1)
            ret = ret * a % p;
    return ret;
}
void init() {
    mul[0] = 1;
    for (int i = 1; i <= N; i ++)
        mul[i] = mul[i - 1] * i % mod;
}
int inv(int x) { return fp(x, mod - 2, mod); }
int getc(int n, int m) {
    if (n < m) return 0;
    return mul[n] * inv(mul[m]) % mod * inv(mul[n - m]) % mod;
}
signed main() {
	int n, m, k;
    cin >> n >> m >> k;
    // 转化一下：求出n-k名同学做错这些题的方案总数 / 这n名同学所有的可能性
    for (int i = 1; i <= m; i ++) 
        cin >> a[i];
    init();
    int valid = 1, all = 1;
    for (int i = 1; i <= m; i ++)
        valid *= getc(n - k, a[i]), all *= getc(n, a[i]),
        valid %= mod, all %= mod;
    int ans = inv(all) * valid % mod;
    cout << ans;
    return 0;
}
