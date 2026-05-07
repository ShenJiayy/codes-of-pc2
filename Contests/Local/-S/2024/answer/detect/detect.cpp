#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e4;
int d[N + 5], v[N + 5], a[N + 5], p[N + 5];
bool pre[N + 5][N + 5], vis[N + 5], nvis[N + 5];
void solve() {
    int n, m, s, l;
    cin >> n >> m >> s >> l;
    for (int i = 1; i <= n; i ++)
        cin >> d[i] >> v[i] >> a[i];
    for (int i = 1; i <= m; i ++)
        cin >> p[i];
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++) {
            if (p[j] - d[i] > 0 && a[i] < 0 || p[j] - d[i] < 0 && a[i] > 0)
                continue;
            int S = p[j] - d[i];
            if (S < 0) continue;
            double V = sqrt(v[i] * v[i] + 2 * a[i] * S);
            if (V > l) pre[i][j] = 1, vis[i] = 1;
        }
    int cnt = 0, res = m;
    for (int i = 1; i <= n; i ++)
        cnt += vis[i];
    cout << cnt << " ";
    for (int stat = 0; stat < (1 << m); stat ++) {
        memset(nvis, 0, sizeof nvis);
        int cnt1 = 0;
        for (int j = 1; j <= m; j ++) {
            if (stat << j - 1 & 1) {
                for (int i = 1; i <= n; i ++)
                    nvis[i] |= pre[i][j];
                cnt1 ++;
            }
        }
        bool flg = 1;
        for (int i = 1; i <= n; i ++)
            flg = flg && (vis[i] == nvis[i]);
        if (flg) 
            res = min(res, cnt1);
    }
    cout << m - res << endl;
}
signed main() {
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
	int T;
    cin >> T;
    while (T --) 
        solve();
    return 0;
}