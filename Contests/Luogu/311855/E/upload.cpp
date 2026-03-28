#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1500;
vector<int> g[N + 5];
int rd[N + 5], val[N + 5][N + 5], dis[N + 5];
pair<bool, vector<int>> topsort(int n) {
    vector<int> ans, nul;
    queue<int> q;
    for (int i = 1; i <= n; i ++)
        if (rd[i] == 0)
            q.push(i);
    while (!q.empty()) {
        int t = q.front();
        q.pop();
        ans.push_back(t);
        for (int nxt : g[t]) {
            rd[nxt] --;
            if (rd[nxt] == 0)
                q.push(nxt);
        }
    }
    if (ans.size() != n)
        return {0, nul};
    return {1, ans};
}
signed main() {
    #ifndef ONLINE_JUDGE
        // freopen("in.in", "r", stdin);
    #endif
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i ++) {
        int x, y, z;
        cin >> x >> y >> z;
        g[x].push_back(y);
        val[x][y] = z;
        rd[y] ++;
    }
    memset(dis, -0x3f, sizeof dis);
    auto tsa = topsort(n);
    dis[1] = 0;
    auto ts = tsa.second;
    int p1 = -1;
    for (int i = 0; i < ts.size(); i ++)
        if (ts[i] == 1)
            p1 = i;
    if (p1 < 0) {
        cout << -1;
        return 0;
    }
    for (int i = p1; i < ts.size(); i ++) {
        for (int nxt : g[i])
            dis[nxt] = max(dis[nxt], dis[i] + val[i][nxt]);
    }
    if (dis[n] > 2e9)
        cout << -1;
    else
        cout << dis[n];
    return 0;
}