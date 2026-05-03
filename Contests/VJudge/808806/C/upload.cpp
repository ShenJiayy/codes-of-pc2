#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5;
char s[N + 5];
int pa[N + 5], pb[N + 5], pc[N + 5];
signed main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i ++)
		cin >> s[i];
	map<int, int> m1, m2, m3;
	map<pair<int, int>, int> m4;
	m1[0] = m2[0] = m3[0] = 1, m4[{0, 0}] = 1;
	int cnt = 0;
	for (int i = 1; i <= n; i ++) {
		pa[i] = pa[i - 1] + (s[i] == 'A');
		pb[i] = pb[i - 1] + (s[i] == 'B');
		pc[i] = pc[i - 1] + (s[i] == 'C');
		int x = pa[i] - pb[i], y = pb[i] - pc[i], z = pa[i] - pc[i];
		cnt += m1[x] + m2[y] + m3[z] - m4[{x, y}] * 2;
		m1[x] ++, m2[y] ++, m3[z] ++, m4[{x, y}] ++;
	}
	cout << n * (n + 1) / 2 - cnt;
	return 0;
}
