#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5;
bool all[N + 5], vis[N + 5];
int a[6];
inline int hs() {
    return a[1] * 1e4 + a[2] * 1e3 + a[3] * 100 + a[4] * 10 + a[5];
}
signed main() {
    memset(all, 1, sizeof all);
	int T;
    cin >> T;
    while (T --) {
        memset(vis, 0, sizeof vis);
        for (int i = 1; i <= 5; i ++)
            cin >> a[i];
        for (int i = 1; i <= 5; i ++)
            for (int d = 1; d <= 9; d ++) {
                a[i] += d;
                a[i] %= 10;
                vis[hs()] = 1;
                a[i] -= d;
                a[i] += 10;
                a[i] %= 10;
            }
        for (int i = 1; i <= 4; i ++)
            for (int d = 1; d <= 9; d ++) {
                a[i] += d;
                a[i] %= 10;
                a[i + 1] += d;
                a[i + 1] %= 10;
                vis[hs()] = 1;
                a[i] -= d;
                a[i] += 10;
                a[i] %= 10;
                a[i + 1] -= d;
                a[i + 1] += 10;
                a[i + 1] %= 10;
            }
        for (int i = 0; i < N; i ++)
            all[i] = vis[i] && all[i];
    }
    int cnt = 0;
    for (int i = 0; i < N; i ++)
        cnt += all[i];
    cout << cnt;
    return 0;
}