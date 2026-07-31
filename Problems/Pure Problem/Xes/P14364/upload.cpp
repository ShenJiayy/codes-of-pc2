#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 500, mod = 998244353;
bool easy[N + 5];
int c[N + 5], perm[N + 5];
signed main() {
	int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
        cin >> easy[i];
    for (int i = 1; i <= n; i ++)
        cin >> c[i];
    if (m == n) {
        for (int i = 1; i <= n; i ++)
            if (easy[i] == 0)
                return puts("0"), 0;
        for (int i = 1; i <= n; i ++)
            if (c[i] == 0)
                return puts("0"), 0;
        int ans = 1;
        for (int i = 1; i <= n; i ++)
            ans *= i, ans %= mod;
        cout << ans;
        return 0;
    }
    if (n <= 10) {
        int ans = 0;
        for (int i = 1; i <= n; i ++)
            perm[i] = i;
        do {
            int cnt = 0, res = 0;
            for (int i = 1; i <= n; i ++)
                if (easy[i] && cnt >= c[perm[i]])
                    res ++;
                else
                    cnt ++;
            if (res >= m)
                ans ++;
        } while (next_permutation(perm + 1, perm + n + 1));
        cout << ans;
        return 0;
    }
    if (m == 1) {
        int ans = 1;
        for (int i = 1; i <= n; i ++)
            ans *= i, ans %= mod;
        // Reserve Code
        return puts("Reserve."), 0;
    }
    return puts("Not In Support"), 42;
}
