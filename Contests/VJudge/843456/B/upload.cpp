#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const int N = 1e6, K = 64;
bool nbox[K], lbox[K];
ull a[N + 5];
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, m, c, k;
    cin >> n >> m >> c >> k;
    for (int i = 1; i <= n; i ++) 
        cin >> a[i];
    for (int i = 1; i <= n; i ++)
        for (int j = 0; j < k; j ++)
            nbox[j] |= a[i] >> j & 1;
    for (int i = 1; i <= m; i ++) {
        int p, q;
        cin >> p >> q;
        lbox[p] = 1;
    }
    int cnt = k;
    for (int i = 0; i < k; i ++)
        if (!nbox[i] && lbox[i])
            cnt --;
    if (cnt == 64 && n == 0)
        return puts("18446744073709551616"), 0;
    __int128 res = 1;
    res <<= cnt;
    res -= n;
    ull ans = res;
    cout << ans;
    return 0;
}