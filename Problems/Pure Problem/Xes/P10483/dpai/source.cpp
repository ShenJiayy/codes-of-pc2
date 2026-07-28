#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e4;
int a[N + 5], w[N + 5];
signed main() {
	int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    sort(a + 1, a + n + 1, greater<int>());
    int ans = 0;
    for (int i = 1; i <= n; i ++) {
        int p = 0, minn = 9e18;
        for (int j = 1; j <= ans; j ++)
            if (m - w[j] >= a[i] && m - w[j] < minn) {
				minn = m - w[j];
				p = j;
            }
        if (!p)
            w[++ ans] = a[i];
    }
    cout << ans;
    return 0;
}
