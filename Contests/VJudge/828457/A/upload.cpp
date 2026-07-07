#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 6e3;
bool vis[N + 5];
vector<int> g[N + 5];
int dp[N + 5][2], a[N + 5];

void dfs(int id){
    dp[id][0] = 0, dp[id][1] = a[id];
    for (int nxt : g[id]) {
        dfs(nxt);
        dp[id][0] += max(dp[nxt][0], dp[nxt][1]);
        dp[id][1] += dp[nxt][0];
    }
}

signed main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    for (int i = 1; i < n; i ++)  {
        int a, b;
        cin >> a >> b;
        g[b].push_back(a);
        vis[a] = 1;
    }
    int root;
    for (int i = 1; i <= n; i ++)
        if (vis[i] == 0)
            root = i;
    dfs(root);
    cout << max(dp[root][0], dp[root][1]);
    return 0;
}