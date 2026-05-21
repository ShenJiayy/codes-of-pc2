#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 100;
int dis[N + 5][N + 5], w[N + 5];

signed main() {
    #ifndef ONLINE_JUDGE
        freopen("in.in", "r", stdin);
    #endif
    memset(dis, 0x3f, sizeof dis);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++) {
        dis[i][i] = 0;
        int l, r;
        cin >> w[i] >> l >> r;
        if (l)
            dis[i][l] = dis[l][i] = 1;
        if (r)
            dis[i][r] = dis[r][i] = 1;
    }
    for (int k = 1; k <= n; k ++)
        for (int i = 1; i <= n; i ++)
            for (int j = 1; j <= n; j ++)
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
    int minn = 9e18;
    for (int i = 1; i <= n; i ++) {
        int dist = 0;
        for (int j = 1; j <= n; j ++)
            dist += dis[j][i] * w[j];
        minn = min(minn, dist);
    }
    cout << minn;
    return 0;
}