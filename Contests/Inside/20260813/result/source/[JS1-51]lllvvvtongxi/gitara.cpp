#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;
int n, p, ans, a[10][N], cnt[10];

int main () {
	
	freopen ("gitara.in", "r", stdin);
	freopen ("gitara.out", "w", stdout);

	cin >> n >> p;
	for (int i = 1; i <= n; i ++) {
		int x, y;
		cin >> x >> y;
		if (a[x][cnt[x]] < y) {
			ans ++;
			a[x][++ cnt[x]] = y;
			continue;
		}
		if (a[x][cnt[x]] == y) {
			continue;
		}
		while (a[x][cnt[x]] > y && cnt[x] > 0) {
			cnt[x] --;
			ans ++;
		}
		if (a[x][cnt[x]] < y) {
			a[x][++ cnt[x]] = y;
			ans ++;
		}
	}
	
	cout << ans;
	
	return 0;
	
}
