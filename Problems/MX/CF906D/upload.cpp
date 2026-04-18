#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5;
int a[N + 5];
unordered_map<int, int> phi;
inline void read(int& x) {
	char lst = 0;
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
inline int getPhi(int x) {
    if (phi.count(x)) return phi[x];
    int ret = x;
    for (int i = 2; i * i <= x; i ++)
        if (x % i == 0) {
            ret = ret / i * (i - 1);
            while (x % i == 0) x /= i;
        }
    if (x > 1) ret = ret / x * (x - 1);
    phi[x] = ret;
    return ret;
}
inline int mod(int x, int y) {
    if (x < y) return x;
    return x % y + y;
}
inline int fp(int a, int b, int p) {
    int ret = 1;
    for (; b; b >>= 1, a *= a, a = mod(a, p)) 
        if (b & 1)
            ret *= a, ret = mod(ret, p);
    return ret;
} 
int solve(int x, int l, int r) {
    if (x == 1 || l == r) return mod(a[l], x);
    return fp(a[l], solve(getPhi(x), l + 1, r), x);
}
signed main() {
	int n, m, T;
    read(n), read(m);
    for (int i = 1; i <= n; i ++)
        read(a[i]);
    read(T);
    while (T --) {
        int l, r;
        read(l), read(r);
        int ans = solve(m, l, r) % m;
        printf("%lld", ans), puts("");
    }
    return 0;
}