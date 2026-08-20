#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e4;
int col[N + 5];
int n, m, T;
int node[N + 5];
bool edge[N + 5];
int cnt = 0;
void dfs(int id) {
    if (id > n) {
        if ((col[n] == col[1]) ^ edge[n])
            return ;
        cnt ++;
        return ;
    }
    if (node[id] > 0) {
        col[id] = node[id];
        dfs(id + 1);
        return ;
    }
    for (int i = 1; i <= m; i ++)
        if (-node[id] != i && (edge[id] ^ (col[id - 1] != i))) {
            col[id] = i;
            dfs(id + 1);
        }
}
signed main() {
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    cin >> n >> m >> T;
    memset(edge, 0, sizeof edge);
    for (int i = 1; i <= T; i ++) {
        int opt, x, y;
        cin >> opt >> x >> y;
        if (opt == 1) {
            if (node[x] == -y)
                return puts("0"), 0;
            node[x] = y;
        }
        else if (opt == 2) {
            if (node[x] == y)
                return puts("0"), 0;
            node[x] = -y;
        }
        else if (x == y + 1)
            edge[y] = 1;
        else edge[x] = 1;
    }
    dfs(1);
    cout << cnt;
    return 0;
}