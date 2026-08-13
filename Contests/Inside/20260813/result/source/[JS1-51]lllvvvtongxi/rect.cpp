#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 250005;
int n, m, a[N], p[N], ans;
int q[N * 20 + 5], up[N], cnt;

int id (int x, int y) {
	if (x < 1 || y < 1 || x > n || y > m) return 0;
	return (x - 1) * m + y;
}

signed main () {
	
	freopen ("rect.in", "r", stdin);
	freopen ("rect.out", "w", stdout);

	cin >> n >> m;
	
	for (int i = 1; i <= n * m; i ++) {
		cin >> a[i];
		a[i] --;
	}
		
	for (int i = 1; i <= n; i ++ )  {
		for (int j = 1; j <= m; j ++) {
			p[id (i, j)] = a[id (i, j)] + p[id (i - 1, j)] + p[id (i, j - 1)] - p[id (i - 1, j - 1)];
		}
	}
	
//	for (int x_1 = 1; x_1 <= n; x_1 ++) {
//		for (int y_1 = 1; y_1 <= m; y_1 ++) {
//			for (int x_2 = x_1; x_2 <= n; x_2 ++) {
//				for (int y_2 = y_1; y_2 <= m; y_2 ++) {
//					int i = x_1 - 1, j = y_1 - 1;
//					if (p[id (x_2, y_2)] - p[id (x_2, j)] - p[id (i, y_2)] + p[id (i, j)] == x_2 * y_2 - x_2 * j - i * y_2 + i * j)
//						ans ++;
//				}
//			}
//		}
//	}

//	cout << id (2, 1) << id (1, 0) << id (5, 7) << id (0, 1) << id (3, 5);
//	cout << id (2, 3);

	if (n < m) {
		for (int x_2 = 1; x_2 <= n; x_2 ++) {
			for (int x_1 = 0; x_1 < x_2; x_1 ++) {
				q[N * 10] = 1;
				for (int y_2 = 1; y_2 <= m; y_2 ++) {
					int sum = p[id (x_2, y_2)] - p[id (x_1, y_2)];
					sum += N * 10;
					ans += q[sum];
					q[sum] ++;
					up[y_2] = sum;
				}
				for (int i = 0; i <= m; i ++) {
					q[up[i]] = 0;
					up[i] = 0;	
				}
				q[N * 10] = 0;
				up[0] = N * 10;
			}
		}
	}
	
	if (n >= m) {
		for (int y_1 = 1; y_1 <= m; y_1 ++) {
			for (int y_2 = y_1; y_2 <= m; y_2 ++) {
				q[N * 10] = 1;
				for (int x_2 = 1; x_2 <= n; x_2 ++) {
					int j = y_1 - 1;
					int sum = p[id (x_2, y_2)] - p[id (x_2, j)];
					sum += N * 10;
					ans += q[sum];
					q[sum] ++;
					up[x_2] = sum;
				}
				for (int i = 1; i <= n; i ++) {
					q[up[i]] = 0;
				}
				q[N * 10] = 0;
			}
		}
	}
	
	cout << ans;

	return 0;	
	
}
