#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int n, k, ans = 1e9;
char s[N];
int J, O, I;
int p[N][3];

int main () {
	
	freopen ("jjooii.in", "r", stdin);
	freopen ("jjooii.out", "w", stdout);

	cin >> n >> k;
	for (int i = 1; i <= n; i ++) {
		cin >> s[i];
		if (s[i] == 'J') J ++;
		if (s[i] == 'O') O ++;
		if (s[i] == 'I') I ++;
	}
	if (J < k || O < k || I < k) {
		cout << -1;
		return 0;
	}
	for (int i = 1; i <= n; i ++) {
		p[i][0] = p[i - 1][0];
		p[i][1] = p[i - 1][1];
		p[i][2] = p[i - 1][2];
		if (s[i] == 'J') p[i][0] ++;
		if (s[i] == 'O') p[i][1] ++;
		if (s[i] == 'I') p[i][2] ++;
	}
	
	for (int i = 1; i <= n - k * 3 + 1; i ++) {
		int sum = 0;
		if (s[i] != 'J') continue;
		if (J - p[i - 1][0] < k) continue;
		if (O - p[i - 1][1] < k) continue;
		if (I - p[i - 1][2] < k) continue;
		int l = i, r = n, mj = 0;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (p[mid][0] - p[i - 1][0] >= k) {
				mj = mid;
				r = mid - 1;
			}
			else l = mid + 1;
		}
		if (O - p[mj][1] < k) continue;
		if (I - p[mj][2] < k) continue;
		sum += mj - i + 1 - k;
		l = mj + 1, r = n;
		int mo = 0;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (p[mid][1] - p[mj][1] >= k) {
				mo = mid;
				r = mid - 1;
			}
			else l = mid + 1;
		}
		if (I - p[mo][2] < k) continue;
		sum += mo - mj - k;
		l = mo + 1, r = n;
		int mi = 0;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (p[mid][2] - p[mo][2] >= k) {
				mi = mid;
				r = mid - 1;
			}
			else l = mid + 1;
		}
		sum += mi - mo - k;
		ans = min (ans, sum);
	}
	
	if (ans == 1e9) ans = -1;
	cout << ans;
	
	return 0;
}
