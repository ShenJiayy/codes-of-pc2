#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1500;
vector<int> g[N + 5];
int dp[N + 5][2];
void dfs(int id, int ft) {
	dp[id][1] = 1;
	for (int nxt : g[id]) if (nxt != ft) {
		dfs(nxt, id);
		dp[id][0] += dp[nxt][1];
		dp[id][1] += min(dp[nxt][0], dp[nxt][1]);
	}
}
signed main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++) {
        int u, k;
        cin >> u >> k;
        while (k --) {
        	int v;
        	cin >> v;
        	g[v].push_back(u);
        	g[u].push_back(v);
		}
    }
    int minn = 9e18;
    for (int rt = 0; rt < n; rt ++) {
    	dfs(rt, n);
    	minn = min(minn, min(dp[rt][0], dp[rt][1]));
	}
	cout << minn;
    return 0;
}