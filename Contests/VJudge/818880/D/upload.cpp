#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 3e5;
int a[N + 5], s[N + 5], c, d, n;
inline int cost(int x) {
    int p = upper_bound(a + 1, a + n + 1, x * d) - a;
    return s[n] - s[p - 1] - d * x * (n - p + 1) + c * x;
}
inline int check(int x) {
    return cost(x + 1) - cost(x); 
}
signed main() {
	int T;
    cin >> n >> T;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i ++)
        s[i] = s[i - 1] + a[i];
    while (T --) {
        cin >> c >> d;
        int l = 0, r = (a[n] + d - 1) / d, ans;
        while (l <= r) {
            int mid = l + r >> 1;
            if (check(mid) >= 0)
                ans = mid, r = mid - 1;
            else l = mid + 1;
        }
        cout << cost(ans) << endl;
    }
    return 0;
}
