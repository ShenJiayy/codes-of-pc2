#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 20;
int plc[N + 5], n, m;
set<vector<int>> ans;
void dfs(int id) {
    if (id >= n) {
        vector<int> front(m + 1);
        for (int i = 1; i <= n; i ++)
            front[plc[i]] = i;
        ans.insert(front);
        return ;
    }
    if (plc[id] < m) {
        plc[id + 1] = plc[id] + 1;
        dfs(id + 1);
    }
    if (plc[id] > 1) {
        plc[id + 1] = plc[id] - 1;
        dfs(id + 1);
    }
}
signed main() {
    freopen("kocke.in", "r", stdin);
    freopen("kocke.out", "w", stdout);
    cin >> n >> m;
    if (n > 30) 
        return puts("For large cases, it didn't support!"), -1;
    for (int i = 1; i <= m; i ++) {
        plc[1] = i;
        dfs(1);
    }
    cout << ans.size();
    return 0;
}