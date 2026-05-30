#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5;
char s[N + 5], p[3] = {'R', 'G', 'B'};
signed main() {
	int n, ans = 0;
	scanf("%lld%s", &n, s);
	for (int i = 0; i < n; i ++)
		if (s[i] != p[i % 3])
			ans ++;
	cout << ans;
	return 0;
}