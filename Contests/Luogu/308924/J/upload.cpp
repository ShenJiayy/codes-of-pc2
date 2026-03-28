#include <bits/stdc++.h>
using namespace std;
#define int long long
const int M = 60, N = 1e8, MOD = 1e5 + 3;
int ax[M + 5];
int qpow(int a, int b, int p) {
    int ans = 1;
    a %= MOD;
    ax[0] = a;
    for (int i = 1; i <= 60; i ++)
        ax[i] = ax[i - 1] % p * ax[i - 1] % p;
    for (int i = 0; i <= 60; i ++)
        if (b >> i & 1)
            ans *= ax[i], ans %= p;
    return ans;
}
signed main() {
    #ifndef ONLINE_JUDGE
        freopen("in.in", "r", stdin);
    #endif
    int n, m;
    cin >> m >> n;
    /*
第一个人 1~m
第二个人 1~m - 1
第三个人 1~m - 1
... ... ... ...
以此类推
总情况：m^n
越狱情况：m * (m-1)^(n-1)
    */
    cout << (qpow(m, n, MOD) - m % MOD * qpow(m - 1, n - 1, MOD) % MOD + MOD) % MOD;
    return 0;
}