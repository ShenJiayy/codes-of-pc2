#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5;
int f1[N + 5], f2[N + 5], tme[N + 5];
pair<int, int> p[N];
void solve(int n, int m, int f[]) {
	for (int i = 0; i < m; i ++)
		scanf("%lld %lld", &p[i].first, &p[i].second);
	sort(p, p + m);
	int cur = 0;
	for (int i = 0; i < m; i ++) {
		tme[i] = 0;
		int a = p[i].first, b = p[i].second, pos = 1;
		while (pos <= cur && tme[pos] > a) pos ++;
		f[pos] ++, tme[pos] = b;
		if (pos >= cur) cur = pos;
	}
	for (int i = 1; i <= n; i ++)
		f[i] += f[i - 1];
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