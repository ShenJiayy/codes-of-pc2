#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e7;
int phi[N + 5];
void initPhi() {
    phi[1] = 1;
    for (int i = 2; i <= N; i ++) 
        if (!phi[i])
            for (int j = i; j <= N; j += i) {
                if (!phi[j])
                    phi[j] = j;
                phi[j] = phi[j] / i * (i - 1);
            }
}
int fp(int a, int b, int p) {
    int ret = 1;
    for (; b; b >>= 1, a *= a, a %= p) 
        if (b & 1)
            ret *= a, ret %= p;
    return ret;
} 
int solve(int x) {
    if (x == 1) return 0;
    return fp(2, solve(phi[x]) + phi[x], x);
}
signed main() {
    initPhi();
	int T;
    scanf("%lld", &T);
    while (T --) {
        int p;
        scanf("%lld", &p);
        printf("%lld\n", solve(p));
    }
    return 0;
}
