#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5;
int a[N + 5], s[N + 5];
signed main() {
    freopen("book.in", "r", stdin);
    freopen("book.out", "w", stdout);
	int n, m, p, q;
    cin >> n >> m >> p >> q;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    for (int i = 1; i <= n; i ++)
    	s[i] = s[i - 1] + a[i];
    int ans = -1;
    for (int i = 1; i <= n; i ++) {
	    // int tme = q * i, sum = 0;
	    // for (int j = i; j >= 1; j --) 
	    //     if (tme + p - q <= m)
	    //         tme += p - q, sum += a[j];
        // ans = max(ans, sum);
	    int l = 1, r = i, j = i - (m - q * i) / (p - q) + 1;
        if (j < 1) j = 1;
        if (j > n) break;
        ans = max(ans, s[i] - s[j - 1]);
	} 
    cout << ans;
    return 0;
    
}
