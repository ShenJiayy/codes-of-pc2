#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
const int N = 20, M = 100;
int c[N + 5], n, m, k, cnt;
pii e[M + 5];
bool vis[N + 5];
void dfs(int id) {
    if (id > n) {
        for (int x = 0; x < (1 << k); x ++) {
            bool valid = 1;
            for (int i = 1; i <= n; i ++)
                if (vis[i])
                    c[i] ^= x;
            for (int i = 1; i <= m; i ++)
                if (c[e[i].first] == c[e[i].second])
                    valid = 0;
            cnt += valid;
            for (int i = 1; i <= n; i ++)
                if (vis[i])
                    c[i] ^= x;
        }
        return ;
    }
    vis[id] = 0;
    dfs(id + 1);
    vis[id] = 1;
    dfs(id + 1);
}
signed main() {
    freopen("oplus.in", "r", stdin);
    freopen("oplus.out", "w", stdout);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i ++)
        cin >> c[i];
    for (int i = 1; i <= m; i ++)
        cin >> e[i].first >> e[i].second;
    dfs(1);
    cout << cnt;
    return 0;
}