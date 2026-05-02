#include <bits/stdc++.h>
using namespace std;
#define int long long
const int x3 = 1e6, x4 = 32000;
bool isPrime[x4];
int pw3[x3], prime[x4], cnt;
void init() {
    for (int i = 1; i <= x3; i ++)
        pw3[i] = i * i * i;
    memset(isPrime, 1, sizeof isPrime);
    isPrime[0] = isPrime[1] = 0;
    for (int i = 2; i <= x4; i ++) 
        if (isPrime[i]) 
            for (int j = i + i; j <= x4; j += i)
                isPrime[j] = 0;
    for (int i = 2; i <= x4; i ++)
        if (isPrime[i])
            prime[++ cnt] = i;
}
int solve(int x) {
    int ans = 1;
    for (int i = 1; i <= cnt && prime[i] <= x; i ++) {
        int cc = 0;
        while (x % prime[i] == 0) {
            cc ++, x /= prime[i];
            if (cc >= 3)
                ans *= prime[i], cc -= 3;
        }
    }
    int k = lower_bound(pw3 + 1, pw3 + x3 + 1, x) - pw3;
    if (k * k * k == x)
        return ans * k;
    return ans;
}
signed main() {
    init();
    int T;
    cin >> T;
    while (T --) {
        int x;
        cin >> x;
        cout << solve(x) << endl;
    }
    return 0;
}