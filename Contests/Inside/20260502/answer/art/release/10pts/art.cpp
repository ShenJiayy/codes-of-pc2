#include <bits/stdc++.h>
using namespace std;
#define int long long
#define judge
const int N = 5e5;
int a[N + 5], b[N + 5], n, ans = -9e18;
bool vis[N + 5];
void dfs(int id) {
    if (id > n) {
        int maxn = -9e18, minn = 9e18, sum = 0;
        for (int i = 1; i <= n; i ++)
            if (vis[i])
                maxn = max(maxn, a[i]), minn = min(minn, a[i]), sum += b[i];
        if (sum != 0)
            ans = max(ans, sum + minn - maxn);
        return ;
    }
    vis[id] = 0;
    dfs(id + 1);
    vis[id] = 1;
    dfs(id + 1);
}
signed main() {
    #ifdef judge
        freopen("art.in", "r", stdin);
        freopen("art.out", "w", stdout);
    #else
        freopen("data.in", "r", stdin);
        freopen("data.out", "w", stdout);
        freopen("data.log", "w", stderr);
    #endif
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i] >> b[i];
    dfs(1);
    cout << ans;
    return 0;
}
