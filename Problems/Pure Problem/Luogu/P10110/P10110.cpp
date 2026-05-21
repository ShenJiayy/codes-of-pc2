#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e5, INF = 1e9;
int vl[N + 5], dis[N + 5];
vector<int> v[N + 5];

int bfs(int a, int b) {
    queue<int> q;
    q.push(a);
    memset(dis, 0x3f, sizeof dis);
    dis[a] = 0;
    while (!q.empty()) {
        int t = q.front();
        q.pop();
        for (int next : v[t])
            if (dis[next] > dis[t] + 1) {
                dis[next] = dis[t] + 1;
                q.push(next);
            }
    }
    return dis[b];
}

signed main() {
    #ifndef ONLINE_JUDGE
        freopen("input/1.in", "r", stdin);
    #endif
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    for (int i = 0; i < n; i ++)
        cin >> vl[i];
    for (int i = 1; i <= m; i ++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
    }
    int ans = bfs(x, y);
    if (ans >= INF)
        cout << "No solution";
    else
        cout << vl[y] - vl[x] + ans;
    return 0;
}