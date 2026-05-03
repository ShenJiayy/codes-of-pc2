#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 3e5;
int nxt[N + 5], tail[N + 5];
vector<int> pv[N + 5], v[N + 5];
bool vist[N + 5], vis[N + 5], viss[N + 5];
signed main() {
	int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i ++)
        tail[i] = i;
    while (q --) {
        int s, t;
        cin >> s >> t;
        nxt[s] = t;
        vist[t] = 1;
        viss[s] = 1;
    }
    for (int i = 1; i <= n; i ++) {
        if (vist[i] && vis[i]) continue;
        int p = i;
        while (p) pv[i].push_back(p), p = nxt[p], vis[p] = 1;
    }
    for (int i = 1; i <= n; i ++) if (!pv[i].empty()) v[*(pv[i].end() - 1)] = pv[i];
    for (int i = 1; i <= n; i ++) {
        if (viss[i]) {
            cout << "0 ";
            continue;
        }
        cout << v[i].size() << " ";
    }
    return 0;
}
