#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 150;
int x[N + 5], y[N + 5];
double dis[N + 5][N + 5], mdis[N + 5];
double MAXDIS = 9e18; //原值141421.35623731

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
    memset(dis, 0x7f, sizeof dis);
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= n; j ++) {
            char c;
            cin >> c;
            if (c == '1')
                dis[i][j] = calc(i, j);
        }
    for (int i = 1; i <= n; i ++)
        dis[i][i] = 0;
    for (int k = 1; k <= n; k ++)
        for (int i = 1; i <= n; i ++)
            for (int j = 1; j <= n; j ++)
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= n; j ++)
            if (dis[i][j] < MAXDIS)
                mdis[i] = max(mdis[i], dis[i][j]);
    double Resault1 = *max_element(mdis + 1, mdis + n + 1), Resault2 = 9e18;
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= n; j ++)
            if (dis[i][j] > MAXDIS)
                Resault2 = min(Resault2, mdis[i] + mdis[j] + calc(i, j));
    double ans = max(Resault1, Resault2);
    // printf("%.6lf %.6lf %.6lf", ans, Resault1, Resault2);
    freopen("output.csv", "w", stdout);
    printf("i,mdis[i]\n");
    for (int i = 1; i <= n; i ++)
        printf("%lld,%.6lf\n", i, mdis[i]);
    return 0;
}

// 新的大牧场的直径不一定比原来的两个牧场大