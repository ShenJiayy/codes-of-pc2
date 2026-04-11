#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5;
int f1[N + 5], f2[N + 5], tme[N + 5];
void solve(int n, int m, int s[]) {
	map<int, int> depart;
	for (int i = 1; i <= m; i ++) {
		int a, b;
		scanf("%lld %lld", &a, &b);
		depart[a] = b;
	}
	s[0] = 0;
	for (int i = 1; i <= n; i ++) {
		s[i] = s[i - 1];
		auto it = depart.begin();
		while (it != depart.end()) {
			s[i] ++;
			// Go next.
			int b = it->second;
			depart.erase(it);
			it = depart.upper_bound(b);
		}
	}
}
signed main() {
	int n, m1, m2;
	scanf("%lld %lld %lld", &n, &m1, &m2);
	solve(n, m1, f1);
	solve(n, m2, f2);
	int maxn = 0;
	for (int i = 0; i <= n; i ++)
		maxn = max(maxn, f1[i] + f2[n - i]);
	printf("%lld", maxn);
	return 0;
}