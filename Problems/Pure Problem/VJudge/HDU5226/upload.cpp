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
const int N = 1e5;
int mul[N + 5], inv[N + 5];
void init(int n, int p) {
    mul[0] = inv[0] = 1;
    for (int i = 1; i <= n; i ++) {
        mul[i] = mul[i - 1] * i % p;
        inv[i] = fp(mul[i], p - 2, p);
    }
}
int getc(int n, int m, int p) {
	if (n > m) return 0;
	// if (m > n - m) m = n - m;
	return mul[m] * inv[n] % p * inv[m - n] % p;
}
int C(int n, int m, int p) {
    if (n > m) return 0;
    if (m >= p) return C(n / p, m / p, p) * getc(n % p, m % p, p) % p;
    return getc(n, m, p);
}
signed main() {
    int x1, y1, x2, y2, p;
    while (cin >> x1 >> y1 >> x2 >> y2 >> p) {
        init(min(x2 + 1, p - 1), p);
        int ans = 0;
        for (int i = y1; i <= y2; i ++)
            ans += C(i + 1, x2 + 1, p) - C(i + 1, x1, p), ans %= p;
        ans += p, ans %= p;
        cout << ans << endl;
    }
    return 0;
}

