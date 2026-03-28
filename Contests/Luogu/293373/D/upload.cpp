#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e6, mod = 998244353;
int a[N + 5];
bool vis[N + 5];
signed main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i ++) a[i] = i - 1;
    int sum = 0;
    do {
        memset(vis, 0, sizeof vis);
        for (int i = 1; i <= m; i ++)
            for (int j = i; j <= m; j ++) {
                for (int k = i; k <= j; k ++)
                    vis[a[k]] = 1;
            }
        for (int i = 1; i <= m + 1; i ++)
            sum += vis[i], sum %= mod;
    } while (next_permutation(a + 1, a + m + 1));
    cout << sum;
    return 0;
}