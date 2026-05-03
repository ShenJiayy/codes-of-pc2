#include <bits/stdc++.h>
using namespace std;
#define int long long
#define local
const int N = 2e5;
int cnt[N + 5];
signed main() {
    #ifdef local
        freopen("in.in", "r", stdin);
    #endif
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
        cnt[i] = n - 1;
    for (int i = 1; i <= m; i ++) {
        int x, y;
        cin >> x >> y;
        cnt[x] --, cnt[y] --;
    }
    for (int i = 1; i <= n; i ++) 
        cout << cnt[i] * (cnt[i] - 1) * (cnt[i] - 2) / 6 << " ";
    return 0;
}
// 11:10