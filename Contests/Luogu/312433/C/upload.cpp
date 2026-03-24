#include <bits/stdc++.h>
using namespace std;
#define int long long
struct Node {
    int id, stp;
};
const int N = 1000;
vector<int> g[N + 5];
bool stoped[N + 5], vis[N + 5][N + 5];
int a[N + 5], rd[N + 5];
signed main() {
    #ifndef ONLINE_JUDGE
        // freopen("in.in", "r", stdin);
    #endif
    int n, m, ans = 0;
    cin >> n >> m;
    while (m --) {
        memset(stoped, 0, sizeof stoped);
        int k;
        cin >> k;
        for (int i = 1; i <= k; i ++) {
            cin >> a[i];
            stoped[a[i]] = 1;
        }
        for (int i = a[1] + 1; i < a[k]; i ++)
            if (!stoped[i])
                for (int j = 1; j <= k; j ++)
                    if (!vis[i][a[j]]) {
                        rd[a[j]] ++;
                        vis[i][a[j]] = 1;
                        g[i].push_back(a[j]);
                    }
    }
    queue<Node> q;
    for (int i = 1; i <= n; i ++)
        if (rd[i] == 0)
            q.push({i, 1});
    while (!q.empty()) {
        Node t = q.front();
        q.pop();
        ans = max(ans, t.stp);
        for (int nxt : g[t.id]) {
            rd[nxt] --;
            if (rd[nxt] == 0)
                q.push({nxt, t.stp + 1});
        }
    }
    cout << ans;
    return 0;
}