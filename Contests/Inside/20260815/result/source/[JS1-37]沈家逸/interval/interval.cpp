#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 200;
struct Dist {
    int l, r, dis;
} a[N + 5];
int n, m, ans = 9e18;
bool vis[N + 5];
void dfs(int id, int sel) {
    if (id > n) {
        if (sel != m)
            return ;
        int maxl = 0, minr = 9e18;
        for (int i = 1; i <= n; i ++)
            if (vis[i])
                maxl = max(maxl, a[i].l),
                minr = min(minr, a[i].r);
        if (maxl > minr)
            return ;
        int maxn = 0, minn = 9e18;
        for (int i = 1; i <= n; i ++)
            if (vis[i])
                maxn = max(maxn, a[i].dis),
                minn = min(minn, a[i].dis);
        ans = min(ans, maxn - minn);
        return ;
    }
    if (sel < m) {
        vis[id] = 1;
        dfs(id + 1, sel + 1);
    }
    vis[id] = 0;
    dfs(id + 1, sel);
}
signed main() {
	freopen("interval.in", "r", stdin);
	freopen("interval.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
        cin >> a[i].l >> a[i].r, a[i].dis = a[i].r - a[i].l;
    dfs(1, 0);
    if (ans == 9e18)
        puts("-1");
    else cout << ans;
	return 0;
}
