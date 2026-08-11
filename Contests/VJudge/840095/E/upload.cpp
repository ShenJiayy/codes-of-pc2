#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6;
struct Pos {
	int x, y;
} p[N + 5];
vector<pair<int, int>> g[N + 5];
signed main() {
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= k; i ++) {
		char c;
		cin >> p[i].x >> p[i].y >> c;
		if (c == 'L') {
			// I dont want to write it again.
			// hhh
		}
	}
	return 0;
} 
