#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 4000;
int a[N + 5], b[N + 5], dp[N + 5], last[N + 5];
signed main() {
	int n;
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    for (int i = 1; i <= n; i ++)
        cin >> b[i];
    for (int i = 1; i <= n; i ++) {
        int vl = 0;
        for (int j = 1; j <= n; j ++) {
            if (a[i] == b[j]) dp[j] = vl + 1;
            else dp[j] = last[j];
            if (b[j] < a[i]) vl = max(vl, last[j]);
        }
        memcpy(last, dp, sizeof dp);
    }
    cout << *max_element(dp + 1, dp + n + 1);
    return 0;
}
