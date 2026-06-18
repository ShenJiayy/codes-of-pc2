#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1.5e5, M = 15;
int a[N + 5], b[N + 5], p10[M + 5];
signed main() {
	int n;
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    for (int i = 1; i <= n; i ++)
        cin >> b[i];
    sort(b + 1, b + n + 1);
    p10[0] = 1;
    for (int i = 1; i <= M; i ++)
        p10[i] = p10[i - 1] * 10;
    int ans = 0;
    for (int i = 1; i <= n; i ++) 
        for (int k = 0; k <= M; k ++) {
            // a[i] - p10[k] <= b[l], b[r] < p10[k + 1] - a[i];
            int l = lower_bound(b + 1, b + n + 1, p10[k] - a[i]) - b,
            r = lower_bound(b + 1, b + n + 1, p10[k + 1] - a[i]) - b - 1;
            if (l > r) break;
            ans += (r - l + 1) * (k + 1);
        }
    cout << ans;
    return 0;
}
