#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 100;
int x[N + 5], y[N + 5];
double dis[N + 5][N + 5];

double calc(int i, int j) {
    return sqrt(
        (x[i] - x[j]) * 1.0 * (x[i] - x[j]) + 
        (y[i] - y[j]) * 1.0 * (y[i] - y[j])
    );
}

signed main() {
    #ifndef ONLINE_JUDGE
        freopen("in.in", "r", stdin);
    #endif
    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> x[i] >> y[i];
    int m;
    cin >> m;
    memset(dis, 127, sizeof dis);
    for (int i = 1; i <= m; i ++) {
        int a, b;
        cin >> a >> b;
        dis[a][b] = dis[b][a] = calc(a, b);
    }
    for (int i = 1; i <= n; i ++)
        dis[i][i] = 1;
    int s, t;
    cin >> s >> t;
    for (int k = 1; k <= n; k ++)
        for (int i = 1; i <= n; i ++)
            for (int j = 1; j <= n; j ++)
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
    printf("%.2lf", dis[s][t]);
    return 0;
}