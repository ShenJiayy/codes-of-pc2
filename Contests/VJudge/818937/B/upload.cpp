#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int n, k;
    cin >> n >> k;
    int ans = n * k;
    for (int l = 1, r; l <= n; l = r + 1) {
        if (k / l != 0) r = min(k / (k / l), n);
        else r = n;
        ans -= (r + l) * (k / l) * (r - l + 1) / 2;
    }
    cout << ans;
    return 0;
}