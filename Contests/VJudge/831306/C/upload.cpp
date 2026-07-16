#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2500;
struct Node {
	int l, r;
} a[N + 5], b[N + 5];
bool cmp(Node x, Node y) {
	return x.l > y.l;
}
signed main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i ++)
		cin >> a[i].l >> a[i].r;
	for (int i = 1; i <= m; i ++)
		cin >> b[i].l >> b[i].r;
	sort(a + 1, a + n + 1, cmp);
	sort(b + 1, b + m + 1, cmp);
	int ans = 0;
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= m; j ++)
			if (a[i].l <= b[j].l && b[j].l <= a[i].r && b[j].r) {
				ans ++, b[j].r --;
				break;
			}
	cout << ans;
	return 0;
}
