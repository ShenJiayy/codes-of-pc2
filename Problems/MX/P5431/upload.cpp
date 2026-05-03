#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pc(x) putchar(x)
const int N = 5e6;
int a[N + 5], pre[N + 5], post[N + 5], s[N + 5];
inline void read(int& x) {
	char lst;
	while (!isdigit(lst))
		lst = getchar();
	x = 0;
	while (isdigit(lst)) {
		x = x * 10 + lst - '0';
		lst = getchar();
	}
}
inline void print(int x) {
	int a[20] = {}, curr = 0;
	for (; x; x /= 10) a[++ curr] = x % 10;
	for (int i = curr; i >= 1; i --)
		putchar(a[i] + '0');
}
int fp(int a, int b, int p) {
	int ret = 1;
	for (; b; b >>= 1, a = a * a % p)
		if (b & 1)
			ret = ret * a % p;
	return ret;
}
signed main() {
	int n, p, k;
	read(n), read(p), read(k);
	for (int i = 1; i <= n; i ++)
		read(a[i]);
	pre[0] = 1;
	for (int i = 1; i <= n; i ++)
		pre[i] = pre[i - 1] * a[i] % p;
	post[n + 1] = 1;
	for (int i = n; i >= 1; i --)
		post[i] = post[i + 1] * a[i] % p;
	int Sinv = fp(pre[n], p - 2, p), s = k, ans = 0;
	for (int i = 1; i <= n; i ++)
		ans += s * (pre[i - 1] * post[i + 1] % p * Sinv % p) % p,
		ans %= p, s = s * k % p;
	printf("%lld", ans);
	return 0;
}
