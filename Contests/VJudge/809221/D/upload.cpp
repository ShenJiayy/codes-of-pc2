#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5;
int dp[N + 5], c[9], d[9];
int cal(int x) { return c[x] * (d[x] + 1); } 
signed main() {
	for (int i = 1; i <= 4; i ++)
		cin >> c[i];
	dp[0] = 1;
	for (int i = 1; i <= 4; i ++)
		for (int j = c[i]; j <= N; j ++)
			dp[j] += dp[j - c[i]];
	int T;
	cin >> T;
	while (T --) {
		for (int i = 1; i <= 4; i ++) cin >> d[i];
		int s;
		cin >> s;
		int ans = dp[s];
		if (s >= cal(1)) ans -= dp[s - cal(1)];
		if (s >= cal(2)) ans -= dp[s - cal(2)];
		if (s >= cal(3)) ans -= dp[s - cal(3)];
		if (s >= cal(4)) ans -= dp[s - cal(4)];
		if (s >= cal(1) + cal(2)) ans += dp[s - cal(1) - cal(2)];
		if (s >= cal(1) + cal(3)) ans += dp[s - cal(1) - cal(3)];
		if (s >= cal(1) + cal(4)) ans += dp[s - cal(1) - cal(4)];
		if (s >= cal(2) + cal(3)) ans += dp[s - cal(2) - cal(3)];
		if (s >= cal(2) + cal(4)) ans += dp[s - cal(2) - cal(4)];
		if (s >= cal(3) + cal(4)) ans += dp[s - cal(3) - cal(4)];
		if (s >= cal(1) + cal(2) + cal(3)) 	
			ans -= dp[s - cal(1) - cal(2) - cal(3)];
		if (s >= cal(1) + cal(2) + cal(4)) 	
			ans -= dp[s - cal(1) - cal(2) - cal(4)];
		if (s >= cal(1) + cal(3) + cal(4)) 	
			ans -= dp[s - cal(1) - cal(3) - cal(4)];
		if (s >= cal(2) + cal(3) + cal(4)) 	
			ans -= dp[s - cal(2) - cal(3) - cal(4)];
		if (s >= cal(1) + cal(2) + cal(3) + cal(4)) 	
			ans += dp[s - cal(1) - cal(2) - cal(3) - cal(4)];
		cout << ans << endl;
	}
	return 0;
}
