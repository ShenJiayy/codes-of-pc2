#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 12, M = 1 << 12;
int g[N + 5][N + 5], val[M + 5][M + 5], dp[N + 5][M + 5];
void init(int n) {
    for (int i = 1; i < M; i ++)
        for (int stat = i; stat; stat = (stat - 1) & i) {
            if (stat == i) continue;
            
        }
}
int solve(int rt, int n) {

}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
	int n, m;
    cin >> n >> m;
    if (n == 1) 
        return puts("0"), 0;
    memset(g, 0x3f, sizeof g);
    for (int i = 1; i <= m; i ++) {
        int a, b, c;
        cin >> a >> b >> c;
        a --, b --;
        g[a][b] = g[b][a] = min(g[a][b], c);
    }
    init(n);
    int ans = 9e18;
    for (int i = 0; i < n; i ++)
        ans = min(ans, solve(i, n));
    cout << ans;
    return 0;
}