#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 20;
int a[N + 5], n, r;
int cntt[N + 5], ans;
void dfs(int id, int emp) {
	if (emp > n - id + 1)
		return; 
	if (id > n) { ans ++; return; }
	for (int i = 1; i <= r; i ++) {
		a[id] = i;
		cntt[i] ++;
		if (cntt[i] == 1) 
			emp --;
		dfs(id + 1, emp);
		cntt[i] --;
		if (cntt[i] == 0) 
			emp ++;
	}
}
signed main() {
	cin >> n >> r;
	dfs(1, r);
	cout << ans;
	return 0;
}
