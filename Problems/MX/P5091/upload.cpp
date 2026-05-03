#include <bits/stdc++.h>
using namespace std;
#define int long long
int getphi(int m) {
    int mcp = m, phi = 1;
    for (int i = 2; i * i <= mcp; i ++) {
        if (mcp % i) continue ;
        phi *= i - 1;
        mcp /= i;
        while (mcp % i == 0) phi *= i, mcp /= i;
    }
    if (mcp > 1) phi *= mcp - 1;
    return phi;
}
int fp(int a, int b, int p) {
    int ret = 1;
    for (; b; b >>= 1, a = a * a % p)
        if (b & 1)
            ret *= a, ret %= p;
    return ret;
}
signed main() {
	int a, m;
    scanf("%lld%lld", &a, &m);
    a %= m;
    int phi = getphi(m);
    char ch;
    do {ch = getchar();} while (ch < '0' || ch > '9');
    int b = ch - '0';
    bool flg = 0;
    if (b >= phi)
        flg = 1, b %= phi;
    while (1) {
        ch = getchar();
        if (ch > '9' || ch < '0') break;
        if (b >= phi)
            flg = 1, b %= phi;
        b = b * 10 + ch - '0';
    }
    if (flg)
        b += phi;
    printf("%lld", fp(a, b, m));
    return 0;
}
