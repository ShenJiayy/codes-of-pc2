#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
int fp(int a, int b, int p) {
    int ret = 1;
    for (; b; b >>= 1, a = a * a % p)
        if (b & 1)
            ret = ret * a % p;
    return ret;
}
signed main() {
	int w, n, _;
    cin >> w >> _ >> n;
    int inv = fp(fp(2, n, mod), mod - 2, mod);
    inv *= w, inv %= mod;
    cout << inv;
    return 0;
}
