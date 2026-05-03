#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 100;
bool dis[N + 5][N + 5];
int d[N + 5];

signed main() {
    #ifndef ONLINE_JUDGE
        freopen("in.in", "r", stdin);
    #endif
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i ++) {
        int a, b;
        cin >> a >> b;
        dis[a][b] = 1;
    }
    for (int i = 1; i <= n; i ++)
        dis[i][i] = 0;
    for (int k = 1; k <= n; k ++)
        for (int i = 1; i <= n; i ++)
            for (int j = 1; j <= n; j ++)
                dis[i][j] |= dis[i][k] & dis[k][j];
    int cnt = 0;
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= n; j ++)
            if (dis[i][j])
                d[i] ++, d[j] ++;
    for (int i = 1; i <= n; i ++)
        cnt += (d[i] == n - 1);
    cout << cnt;
    return 0;
}