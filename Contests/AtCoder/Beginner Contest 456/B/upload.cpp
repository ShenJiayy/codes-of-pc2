#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[5][10], c[6], cnt;
void dfs(int id) {
	if (id > 3) {
		bool valid = (
			(c[1] == 4 && c[2] == 5 && c[3] == 6) ||
			(c[1] == 4 && c[2] == 6 && c[3] == 5) ||
			(c[1] == 5 && c[2] == 4 && c[3] == 6) ||
			(c[1] == 5 && c[2] == 6 && c[3] == 4) ||
			(c[1] == 6 && c[2] == 4 && c[3] == 5) ||
			(c[1] == 6 && c[2] == 5 && c[3] == 4)
		);
		cnt += valid;
//		cout << c[1] << c[2] << c[3] << " " << valid << endl;
		return ;
	}
	for (int i = 1; i <= 6; i ++) {
		c[id] = a[id][i];
		dfs(id + 1);
	}
}
signed main() {
	for (int i = 1; i <= 3; i ++) 
		for (int j = 1; j <= 6; j ++)
			cin >> a[i][j];
	dfs(1);
	cout << 1.0 * cnt / 216.0;
//	cout << cnt;
	return 0;
}