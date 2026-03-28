#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e4, inf = 1e9;
struct Node {
    int id, w;
};
vector<Node> g[N + 5];
int maxline[N + 5], vis[N + 5];
int res, q[N + 5], tail, m;
void dfs(int id, int ft, int lim) {
    for (Node nxt : g[id])
        if (nxt.id != ft)
            dfs(nxt.id, id, lim);
    tail = 0;
    for (Node nxt : g[id])
        if (nxt.id != ft)
            q[++ tail] = maxline[nxt.id] + nxt.w;
    sort(q + 1, q + tail + 1);
    while (tail && q[tail] >= lim)
        tail --, res --;
    for (int i = 1; i <= tail; i ++) 
        if (vis[i] != id) {
            int l = i + 1, r = tail, eans = tail + 1;
            while (l <= r) {
                int mid = l + r >> 1;
                if (q[i] + q[mid] >= lim)
                    eans = mid, r = mid - 1;
                else l = mid + 1;
            }
            while (vis[eans] == id && eans <= tail) 
                eans ++;
            if (eans <= tail)
                vis[eans] = vis[i] = id, res --; 
        }
    maxline[id] = 0;
    for (int i = tail; i >= 1; i --)
        if (vis[i] != id) {
            maxline[id] = q[i];
            break;
        }
}
bool check(int len) {
    res = m;
    memset(vis, 0, sizeof vis);
    dfs(1, 0, len);
    return res <= 0;
}
signed main() {
	int n;
    cin >> n >> m;
    for (int i = 1; i < n; i ++) {
        int u, v, l;
        cin >> u >> v >> l;
        g[u].push_back({v, l});
        g[v].push_back({u, l});
    }
    int l = 0, r = inf, ans = 0;
    while (l <= r) {
        int mid = l + r >> 1;
        if (check(mid)) 
            ans = mid, l = mid + 1;
        else r = mid - 1;
    }
    cout << ans;
    return 0;
}