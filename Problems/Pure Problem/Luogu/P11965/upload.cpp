#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5;
char s[N + 5];
int a[N + 5], cnt[(1 << 26) + 5];
signed main() {
	int n;
    scanf("%lld%s", &n, s + 1);
    for (int i = 1; i <= n; i ++)
        a[i] = a[i - 1] ^ (1 << s[i] - 'a');
    int ans = 0;
    cnt[0] = 1;
    for (int r = 1; r <= n; r ++) {
        ans += cnt[a[r]];
        cnt[a[r]] ++;
    }
    cout << ans;
    return 0;
}
