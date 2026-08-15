#include <bits/stdc++.h>
using namespace std;

const int N = 505;
int h, w, q, a[N][N], b[N][N];

int main () {
	
	freopen ("mask.in", "r", stdin);
	freopen ("mask.out", "w", stdout);

	cin >> h >> w >> q;
	while (q --) {
		int op;
		cin >> op;
		if (op == 1) {
			int x, y, c;
			cin >> x >> y >> c;
			if (!b[x][y]) a[x][y] = c;
			if (!b[x + 1][y]) a[x + 1][y] = c;
			if (!b[x][y + 1]) a[x][y + 1] = c;
			if (!b[x + 1][y + 1]) a[x + 1][y + 1] = c;
		}
		if (op == 2) {
			int x, y;
			cin >> x >> y;
			b[x][y] = b[x + 1][y] = b[x][y + 1] = b[x + 1][y + 1] = 1;
		}
	}
	
	for (int i = 1; i <= h; i ++) {
		for (int j = 1; j <= w; j ++)
			cout << a[i][j] << " ";
		cout << "\n";
	}
	
	return 0;
	
}
