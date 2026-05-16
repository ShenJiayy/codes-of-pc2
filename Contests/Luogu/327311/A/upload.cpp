#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1000;
bool mp[N + 5][N + 5];
int hs[N + 5][N + 5], cs[N + 5][N + 5];
signed main() {
	int T, __;
	cin >> T >> __;
	while (T --) {
		int n, m, c, f;
		scanf("%lld%lld%lld%lld", &n, &m, &c, &f);
		for (int i = 1; i <= n; i ++)
			for (int j = 1; j <= m; j ++)
				cin >> mp[i][j];
		for (int i = 1; i <= n; i ++)
			for (int j = 1; j <= m; j ++)
				hs[i][j] = hs[i][j - 1] + mp[i][j],
				cs[j][i] = cs[j][i - 1] + mp[i][j];
		int cc = 0, ff = 0;
		for (int x1 = 1; x1 <= n; x1 ++)
			for (int x2 = x1 + 2; x2 <= n; x2 ++)
				for (int y0 = 1; y0 <= m; y0 ++)
					for (int y1 = y0 + 1; y1 <= m; y1 ++)
						for (int y2 = y0 + 1; y2 <= m; y2 ++)  {
							cc += 
								hs[x1][y1] == hs[x1][y0 - 1] &&
								hs[x2][y2] == hs[x2][y0 - 1] &&
								cs[y0][x2] == cs[y0][x1 - 1];
							if (hs[x1][y1] == hs[x1][y0 - 1] &&
								hs[x2][y2] == hs[x2][y0 - 1] &&
								cs[y0][x2] == cs[y0][x1 - 1])
									cerr << x1 << " " << x2 << " " << y0 << " " << y1 << " " << y2 << endl;
						}
		for (int x1 = 1; x1 <= n; x1 ++)
			for (int x2 = x1 + 2; x2 <= n; x2 ++)
				for (int x3 = x2 + 1; x3 <= n; x3 ++)
					for (int y0 = 1; y0 <= m; y0 ++)
						for (int y1 = y0 + 1; y1 <= m; y1 ++)
							for (int y2 = y0 + 1; y2 <= m; y2 ++) {
								cc += 
									hs[x1][y1] == hs[x1][y0 - 1] &&
									hs[x2][y2] == hs[x2][y0 - 1] &&
									cs[y0][x3] == cs[y0][x1 - 1];
								if (hs[x1][y1] == hs[x1][y0 - 1] &&
									hs[x2][y2] == hs[x2][y0 - 1] &&
									cs[y0][x3] == cs[y0][x1 - 1])
									cerr << x1 << " " << x2 << " " << x3 << " " << y0 << " " << y1 << " " << y2 << endl;
							}
		cout << cc * c << " " << ff * f << endl;
	}
	return 0;
}
