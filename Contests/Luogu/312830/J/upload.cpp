#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5000, M = 1e5;
struct Node {
    int id, w;
};
bool operator < (Node x, Node y) {
    return x.w > y.w;
}
vector<Node> g[N + 5];
namespace start {
    int dis[N + 5];
    void dijkstra(int s) {
    	memset(dis, 0x3f, sizeof dis);
        priority_queue<Node> q;
        dis[s] = 0;
        q.push({s, 0});
        while (!q.empty()) {
            Node t = q.top();
            q.pop();
            if (t.w > dis[t.id]) continue;
            for (Node nxt : g[t.id])
                if (dis[nxt.id] > dis[t.id] + nxt.w) {
                    dis[nxt.id] = dis[t.id] + nxt.w;
                    q.push({nxt.id, dis[nxt.id]});
                }
        }
    }
}
namespace end {
    int dis[N + 5];
    void dijkstra(int s) {
    	memset(dis, 0x3f, sizeof dis);
        priority_queue<Node> q;
        dis[s] = 0;
        q.push({s, 0});
        while (!q.empty()) {
            Node t = q.top();
            q.pop();
            if (t.w > dis[t.id]) continue;
            for (Node nxt : g[t.id])
                if (dis[nxt.id] > dis[t.id] + nxt.w) {
                    dis[nxt.id] = dis[t.id] + nxt.w;
                    q.push({nxt.id, dis[nxt.id]});
                }
        }
    }
}
struct Edge {
    int st, ed, w;
} e[M + 5];
signed main() {
	int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i ++) {
        cin >> e[i].st >> e[i].ed >> e[i].w;
        g[e[i].st].push_back({e[i].ed, e[i].w});
        g[e[i].ed].push_back({e[i].st, e[i].w});
    }
    start::dijkstra(1), end::dijkstra(n);
    int pthlen = start::dis[n], ans = 9e18;
    for (int i = 1; i <= m; i ++) {
        int st = e[i].st, ed = e[i].ed, w = e[i].w;
        if (start::dis[st] + end::dis[ed] > start::dis[ed] + end::dis[st])
            swap(st, ed);
        int sum = start::dis[st] + end::dis[ed];
        if (sum + w == pthlen) continue;
        ans = min(ans, sum + w);
    }
    int minn = 9e18;
    for (int i = 1; i <= m; i ++) {
        int st = e[i].st, ed = e[i].ed, w = e[i].w;
        if (start::dis[st] + end::dis[ed] > start::dis[ed] + end::dis[st])
            swap(st, ed);
        int sum = start::dis[st] + end::dis[ed] + w;
        if (sum != pthlen) continue;
        minn = min(minn, w);
    }
    ans = min(ans, pthlen + minn * 2);
    cout << ans;
    return 0;
}