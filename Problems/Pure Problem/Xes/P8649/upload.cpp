#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5;
int a[N + 5], s[N + 5], cnt[N + 5];
signed main() {
	int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i ++)
        cin >> a[i], a[i] %= k;
    for (int i = 1; i <= n; i ++)
        s[i] = s[i - 1] + a[i], s[i] %= k;
    int ans = 0;
    cnt[0] = 1;
    for (int i = 1; i <= n; i ++) {
        ans += cnt[s[i]];
        cnt[s[i]] ++;
    }
    cout << ans;
    return 0;
}
