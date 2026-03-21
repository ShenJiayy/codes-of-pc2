#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 9901;
int qpow(int a, int b, int p) {
    a %= p;
	int t = 1;
	while (b) {
		if (b & 1) 
			t = t * a % p;
		a = a * a % p;
		b >>= 1;
	}
	return t;
}
map<int, int> decompose(int x, int b) {
    map<int, int> ans;
    for (int i = 2; i * i <= x; i ++)
        while (x % i == 0)
            ans[i] += b, x /= i;
    if (x != 1)
        ans[x] += b;
    return ans;
}
int ersum(int a, int b) {
    a %= mod;
    if (b == 0) return 1;
    if (b % 2 == 0) 
        return ((ersum(a, b / 2 - 1) % mod * (1 + qpow(a, b / 2, mod)) % mod) % mod + qpow(a, b, mod)) % mod;
    return (ersum(a, b / 2) % mod * (1 + qpow(a, b / 2 + 1, mod)) % mod) % mod;
}
/*
int sum_geo(int a, int n) {
    if (n == 0) return 1; // 只有1项：1
    a %= mod;
    if (n % 2 == 1) {
        // 奇数项：(1+a+...+a^(n/2)) * (1 + a^(n/2 + 1))
        return (sum_geo(a, n / 2) * (1 + qpow(a, n / 2 + 1, mod))) % mod;
    } else {
        // 偶数项：(1+a+...+a^(n/2 -1)) * (1 + a^(n/2)) + a^n
        return (sum_geo(a, n / 2 - 1) * (1 + qpow(a, n / 2, mod)) % mod + qpow(a, n, mod)) % mod;
    }
}
*/
signed main() {
    // #ifndef ONLINE_JUDGE
    //     freopen("in.in", "r", stdin);
    // #endif
    int a, b, sum = 1;
    cin >> a >> b;
    auto cover = decompose(a, b);
    for (auto kv : cover) 
        sum *= ersum(kv.first, kv.second), sum %= mod;
    cout << sum;
    return 0;
}