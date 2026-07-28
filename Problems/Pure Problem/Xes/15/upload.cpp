#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5;
bitset<31> a[N + 5];
int s[31];
void solve() {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i ++) {
        int x;
        cin >> x;
        a[i] = x;
    }
    for (int i = 1; i <= n; i ++)
        for (int j = 0; j <= 30; j ++)
            s[j] += a[i][j] ^ 1;
    int ans = 0;
    for (int j = 30; j >= 0; j --)
        if (k >= s[j]) 
            ans |= (1 << j), k -= s[j];
    cout << ans << endl;
    for (int i = 1; i <= n; i ++)
        a[i] = 0;
    memset(s, 0, sizeof s);
}
signed main() {
	int T;
    cin >> T;
    while (T --)
        solve();
    return 0;
}