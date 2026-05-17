#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e6, mod = 998244353;
int mul[N + 5], inv[N + 5];
int fp(int a, int b, int p) {
    int ret = 1;
    for (; b; b >>= 1, a = a * a % p) if (b & 1) ret = ret * a % p;
    return ret;
}
void init() {
    mul[0] = 1;
    for (int i = 1; i <= N; i ++)
        mul[i] = mul[i - 1] * i % mod;
    inv[N] = fp(mul[N], mod - 2, mod);
    for (int i = N - 1; i >= 0; i --)
        inv[i] = inv[i + 1] * (i + 1) % mod;
}
int getc(int n, int m) {
    if (n - m < 0) return 0;
    return mul[n] * inv[m] % mod * inv[n - m] % mod;
}
signed main() {
    init();
	int x1, x2, x3;
    cin >> x1 >> x2 >> x3;
    int ans = 0;
    for (int i = 1; i <= x2 + 1; i ++)
        ans += getc(x2 + 1, i) * getc(x1 - 1, i - 1) % mod * getc(x2 + x3 - i, x2 - i) % mod, ans %= mod;
    cout << ans;
    return 0;
}
