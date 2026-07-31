#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5;
int v[N + 5], d[N + 5], a[N + 5], p[N + 5];
void solve() {
    int n, m, l, mv;
    cin >> n >> m >> l >> mv;
    for (int i = 1; i <= n; i ++)
        cin >> d[i] >> v[i] >> a[i];
    for (int i = 1; i <= m; i ++)
        cin >> p[i];
    int cnt = 0;
    for (int i = 1; i <= n; i ++)
        if (
            p[m] >= d[i] &&
            v[i] * v[i] + 2 * a[i] * (p[m] - d[i]) > mv * mv
        )
            cnt ++;
    cout << cnt << " " << m - bool(cnt) << endl;
}
signed main() {
	int T;
    cin >> T;
    while (T --) 
        solve();
    return 0;
}