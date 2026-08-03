#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5, mod = 998244353;
int a[N + 5], s0[(N << 2) + 5], s2[(N << 2) + 5], s1[(N << 2) + 5];
int fp(int a, int b, int p) {
	int ret = 1;
	for (; b; b >>= 1, a = a * a % p)
		if (b & 1)
			ret = ret * a % p;
	return ret;
}
const int inv2 = fp(2, mod - 2, mod);
inline void pushup(int id) {
	s0[id] = s0[id * 2] + s0[id * 2 + 1], s0[id] %= mod;
	s1[id] = s1[id * 2] + s1[id * 2 + 1], s1[id] %= mod;
	s2[id] = s2[id * 2] + s2[id * 2 + 1], s2[id] %= mod;
}
inline void modify(int id, int l) {
	s0[id] = a[l] % mod;
	s1[id] = a[l] * l % mod;
	s2[id] = a[l] * l % mod * l % mod;
}
void buildAll(int id, int l, int r) {
    if (l == r) {
        modify(id, l);
		return ;
	}
	int mid = l + r >> 1;
	buildAll(id * 2, l, mid);
	buildAll(id * 2 + 1, mid + 1, r);
	pushup(id);
}
void updateOne(int id, int l, int r, int p) {
    if (l == r) {
        modify(id, l);
        return ;
    }
    int mid = l + r >> 1;
    if (p <= mid)
        updateOne(id * 2, l, mid, p);
    else
        updateOne(id * 2 + 1, mid + 1, r, p);
	pushup(id);
}
int qs0(int id, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) 
		return s0[id];
    int res = 0, mid = l + r >> 1;
    if (ql <= mid)
        res += qs0(id * 2, l, mid, ql, qr), res %= mod;
    if (mid + 1 <= qr)
        res += qs0(id * 2 + 1, mid + 1, r, ql, qr), res %= mod;
    return res;
}
int qs1(int id, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) 
		return s1[id];
    int res = 0, mid = l + r >> 1;
    if (ql <= mid)
        res += qs1(id * 2, l, mid, ql, qr), res %= mod;
    if (mid + 1 <= qr)
        res += qs1(id * 2 + 1, mid + 1, r, ql, qr), res %= mod;
    return res;
}
int qs2(int id, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) 
		return s2[id];
    int res = 0, mid = l + r >> 1;
    if (ql <= mid)
        res += qs2(id * 2, l, mid, ql, qr), res %= mod;
    if (mid + 1 <= qr)
        res += qs2(id * 2 + 1, mid + 1, r, ql, qr), res %= mod;
    return res;
}
inline int calc(int n, int i) {
	int p2 = qs2(1, 1, n, 1, i) * inv2 % mod;
	int p1 = (2 * i + 3) * qs1(1, 1, n, 1, i) % mod * inv2 % mod;
	int p0 = (i + 1) * (i + 2) % mod * inv2 % mod * qs0(1, 1, n, 1, i) % mod;
	return ((p2 - p1 + p0) % mod + mod) % mod;
}
signed main() {
    int n, T;
    cin >> n >> T;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    buildAll(1, 1, n);
    while (T --) {
		int opt;
		cin >> opt;
		if (opt == 1) {
			int p;
			cin >> p;
			cin >> a[p];
			updateOne(1, 1, n, p);
		}
		else {
			int p;
			cin >> p;
			cout << calc(n, p) << endl;
		}
	}
    return 0;
}