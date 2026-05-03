#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5;
int a[N + 5];
signed main() {
    int n, k, ans = 9e18;
    cin >> n >> k;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    for (int i = 1; i <= n; i ++)
        a[i] %= k;
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i ++) 
        ans = min(ans, max(abs(a[i] - (a[i - 1] + k)), abs(a[i] - a[n])));
    cout << ans;
    return 0;
}