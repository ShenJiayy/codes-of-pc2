#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e3, M = 1e4, MOD = 1e9 + 7;
int v[N + 5], ans, n, m;

void dfs(int sum) {
    if (sum >= m) {
        ans += sum == m;
        return ;
    }
    for (int i = 1; i <= n; i ++) 
        dfs(sum + v[i]);
}

signed main() {
	#ifndef ONLINE_JUDGE
		freopen("2/in.in", "r", stdin);
	#endif
	cin >> n >> m;
	for (int i = 1; i <= n; i ++)
		cin >> v[i];
    // dfs(0);
    // cout << ans;
    for (int i = 1; i <= m; i ++)
    return 0;
}