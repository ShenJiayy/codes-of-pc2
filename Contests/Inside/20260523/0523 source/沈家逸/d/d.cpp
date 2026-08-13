#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5;
int a[N + 5];
signed main() {
    freopen("d.in", "r", stdin);
    freopen("d.out", "w", stdout);
    int n, T;
    cin >> n >> T;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    int maxn = *max_element(a + 1, a + n + 1);
    while (T --) {
        int c, d;
        cin >> c >> d;
        int ans = 9e18;
        for (int k = 0; k <= maxn / d + 2; k ++) {
            int sum = 0;
            for (int i = 1; i <= n; i ++)
                sum += max(0ll, a[i] - d * k);
            ans = min(ans, sum + c * k);
        }
        cout << ans << endl;
    }
    return 0;
}