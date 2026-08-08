#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
vector<pii> things;
const int M = 1e4;
int dp[M * 20 + 5];
signed main() {
	int n1, n2, m;
	cin >> n1 >> n2 >> m;
	for (int i = 1; i <= n1; i ++) {
		int vv, ww, cc;
		cin >> vv >> ww >> cc;
		int cnt = 1;
		while (cc >= cnt) {
			cc -= cnt;
			things.push_back({ww * cnt, vv * cnt});
			cnt <<= 1;
		}
		if (cc)
			things.push_back({ww * cc, vv * cc});
	}
	for (pii thing : things) 
		for (int j = m; j >= thing.second; j --)
			dp[j] = max(dp[j], dp[j - thing.second] + thing.first);
	for (int i = 1; i <= n2; i ++) {
		int a, b, c;
		cin >> a >> b >> c;
		for (int j = m; j >= 0; j --) {
			// 看看要用几个 Special Thing
			for (int k = 0; k <= j; k ++)
				dp[j] = max(dp[j], dp[j - k] + (k * k * a + k * b + c));
		}
	}
	cout << *max_element(dp, dp + m + 1);
	return 0;
}
