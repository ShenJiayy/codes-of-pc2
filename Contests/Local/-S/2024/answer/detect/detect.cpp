#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e4;
int d[N + 5], v[N + 5], a[N + 5], p[N + 5];
void solve() {
    int n, m, s, l;
    cin >> n >> m >> s >> l;
    for (int i = 1; i <= n; i ++)
        cin >> d[i] >> v[i] >> a[i];
    for (int i = 1; i <= m; i ++)
        cin >> p[i];
    
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