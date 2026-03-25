#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 200;
bool dis[N + 5][N + 5];
int f[N + 5];
int find(int x) {
    if (f[x] != x)
        f[x] = find(f[x]);
    return f[x];
}
void merge(int x, int y) {
    int ftx = find(x), fty = find(y);
    if (ftx != fty)
        f[ftx] = fty;
}
bool query(int x, int y) {
    return find(x) == find(y);
}

signed main() {
    #ifndef ONLINE_JUDGE
        freopen("in.in", "r", stdin);
    #endif
    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++)
        f[i] = i;
    for (int i = 1; i <= n; i ++) {
        dis[i][i] = 1;
        int x;
        while (1) {
            cin >> x;
            if (!x) break;
            dis[i][x] = 1;
        }
    }
    for (int k = 1; k <= n; k ++)
        for (int i = 1; i <= n; i ++)
            for (int j = 1; j <= n; j ++)
                dis[i][j] |= dis[i][k] & dis[k][j];
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= n; j ++)
            if (dis[i][j])
                f[j] = f[i];
    int cnt = 0;
    for (int i = 1; i <= n; i ++)
        if (find(i) == i)
            cnt ++;
    cout << cnt;
    return 0;
}