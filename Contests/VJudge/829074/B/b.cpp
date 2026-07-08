#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 75000;
struct Node {
	int cls, val;
} a[N * 4 + 5];
bool cmp(Node x, Node y) {
	if (x.val != y.val) return x.val < y.val;
	return x.cls < y.cls;
}
int mp[5], s[5][N * 4 + 5];
int max(int a, int b, int c, int d) {
	return max(max(a, b), max(c, d));
}
int min(int a, int b, int c, int d) {
	return min(min(a, b), min(c, d));
}
signed main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i ++)
		cin >> a[i].val, a[i].cls = 1;
	for (int i = n + 1; i <= n * 2; i ++)
		cin >> a[i].val, a[i].cls = 2;
	for (int i = n * 2 + 1; i <= n * 3; i ++)
		cin >> a[i].val, a[i].cls = 3;
	for (int i = n * 3 + 1; i <= n * 4; i ++)
		cin >> a[i].val, a[i].cls = 4;
	sort(a + 1, a + n * 4 + 1, cmp);
	for (int i = 1; i <= 4; i ++)
		for (int j = 1; j <= n * 4; j ++)
			s[i][j] = s[i][j - 1] + (a[j].cls == i);
	/*
	int ans = 9e18;
	for (int i = 1; i <= n * 4; i ++) {
		memset(mp, 0, sizeof mp);
		for (int j = i; j <= n * 4; j ++) {
			mp[a[j].cls] ++;
			if (mp[1] && mp[2] && mp[3] && mp[4]) {
				ans = min(ans, a[j].val - a[i].val);
				break; // Exit Quickly
			}
		}
	}
	*/
	int ans = 9e18;
	for (int i = 1; i <= n * 4; i ++) {
		s[1][i] = s[1][i - 1] + (a[i].cls == 1);
		s[2][i] = s[2][i - 1] + (a[i].cls == 2);
		s[3][i] = s[3][i - 1] + (a[i].cls == 3);
		s[4][i] = s[4][i - 1] + (a[i].cls == 4);
		
		int pla = lower_bound(s[1] + 1, s[1] + n * 4 + 1, s[1][i - 1] + 1) - s[1];
		int plb = lower_bound(s[2] + 1, s[2] + n * 4 + 1, s[2][i - 1] + 1) - s[2];
		int plc = lower_bound(s[3] + 1, s[3] + n * 4 + 1, s[3][i - 1] + 1) - s[3];
		int pld = lower_bound(s[4] + 1, s[4] + n * 4 + 1, s[4][i - 1] + 1) - s[4];
		
		if (max(pla, plb, plc, pld) <= n * 4)
			ans = min(ans, a[max(pla, plb, plc, pld)].val - a[i].val);
	}
	cout << ans;
	return 0;
}
