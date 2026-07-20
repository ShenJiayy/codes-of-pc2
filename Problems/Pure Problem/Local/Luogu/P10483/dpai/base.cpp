#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 18;
int n, m, a[N + 5], cnt[N + 5], w[N + 5], ans = 9e18;
void dfs(int id, int car) {
    if (car >= ans) return ;
    if (id > n) {
        ans = min(ans, car);
        return ;
    }
    for (int i = 1; i <= car; i ++)
        if (w[i] + a[id] <= m) {
            w[i] += a[id];
            dfs(id + 1, car);
            w[i] -= a[id];
        }
    w[++ car] = a[id];
    dfs(id + 1, car);
    w[car --] = 0;
}
signed main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    dfs(1, 0);
    cout << ans;
    return 0;
}
