#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7, N = 1e6;
int inv[N + 5], mul[N + 5], sinv[N + 5];
int fp(int a, int b, int p) {
    int ret = 1;
    for (; b; b >>= 1, a = a * a % p)
        if (b & 1)
            ret = ret * a % p;
    return ret;
}
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
signed main() {
	int T = read();
    // Initalize.
    mul[0] = 1, inv[0] = 1;
    for (int i = 1; i <= N; i ++)
        mul[i] = (mul[i - 1] * i % mod + mod) % mod, inv[i] = fp(mul[i], mod - 2, mod);
    sinv[0] = inv[0];
    for (int i = 1; i <= N; i ++) {
        if (i & 1)
            sinv[i] = sinv[i - 1] - inv[i];
        else
            sinv[i] = sinv[i - 1] + inv[i];
        sinv[i] = (sinv[i] % mod + mod) % mod;
    }
    while (T --) {
        int n = read(), m = read();
        int res = mul[n] * inv[m] % mod * sinv[n - m] % mod;
        printf("%lld\n", res);
    }
    return 0;
}
