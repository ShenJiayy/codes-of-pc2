#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5;
vector<int> g[N + 5];
signed main() {
	int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i ++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int ans = 0;
    for (int i = 1; i <= n; i ++)
        ans += (g[i].size() - 1) * g[i].size() / 2;
    cout << ans;
    return 0;
}
