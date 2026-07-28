#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	int n, ans = 0, lst = 0;
    cin >> n;
    for (int i = 1; i <= n; i ++) {
        int x;
        cin >> x;
        ans += max(x - lst, 0ll);
        lst = x;
    }
    cout << ans;
    return 0;
}
