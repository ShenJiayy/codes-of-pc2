#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 15;
struct Person {
    int d, c, v;
} a[N + 5];
struct Gift {
    int a, b;
    bool vis;
} g[N + 5];
int n, m, w, ans;
const int dm[] = {0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
void dfs(int id, int mon, int day, int cnt) {
    if (mon > w) return ;
    if (id > n) {
        ans = max(ans, cnt);
        return ;
    }
    dfs(id + 1, mon, day, cnt);
    if (day + a[id].c <= a[id].d)
        dfs(id + 1, mon, day - a[id].c, cnt + a[id].v);
    for (int i = 1; i <= m; i ++)
        if (g[i].vis == 0 && g[i].a <= mon) {
            g[i].vis = 1;
            dfs(id + 1, mon - g[i].a, day, cnt + g[i].b);
            g[i].vis = 0;
        }
}
signed main() {
    int T;
    scanf("%lld", &T);
    while (T --) {
        ans = 0;
        scanf("%lld%lld%lld", &n, &m, &w);
        for (int i = 1; i <= n; i ++) {
            int y, m, d, c, v;
            scanf("%lld-%lld-%lld%lld%lld", &y, &m, &d, &c, &v);
            if (m == 2 && d == 29) continue;
            a[i] = {dm[m] + d, c, v};
        }
        for (int i = 1; i <= m; i ++) 
            scanf("%lld%lld", &g[i].a, &g[i].b), g[i].vis = 0;
        dfs(1, 0, 0, 0);
        cout << ans << endl;
    }
}