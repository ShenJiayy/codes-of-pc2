#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 3e6, M = 5e4;
struct Node {
	int l, r, c;
} a[M + 5];
bool cmp(Node x, Node y) {
	return x.r < y.r;
}
bool vis[N + 5];
signed main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; i ++) 
		cin >> a[i].l >> a[i].r >> a[i].c;
	sort(a + 1, a + m + 1, cmp);
	int ans = 0;
	for (int i = 1; i <= n; i ++) {
		int cnt = 0;
		for (int j = a[i].l; j <= a[i].r; j ++)
			cnt += vis[j];
		for (int j = a[i].r; j >= a[i].l; j --) {
			if (cnt >= a[i].c) break;
			if (vis[j] == 0) {
				ans ++, cnt ++;
				vis[j] = 1;
			}
		}
	}
	cout << ans;
	return 0;
}