// 暴力测试文件
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5;
int a[N + 5], b[N + 5], n;
// 领带选人
int sel[N + 5], ans;
bool vis[N + 5];
void dfs(int id, int exp) {
    if (id > n + 1) {
        int res = 0;
        for (int i = 1; i <= n + 1; i ++)
            if (i != exp)
                res = max(res, max(a[i] - b[sel[i]], 0ll));
        ans = min(ans, res);
        return ;
    }
    if (exp == id) {
        dfs(id + 1, exp);
        return ;
    }
    for (int i = 1; i <= n; i ++)
        if (!vis[i]) {
            vis[i] = 1;
            sel[id] = i;
            dfs(id + 1, exp);
            vis[i] = 0;
        }
}
signed main() {
	freopen("tie.in", "r", stdin);
	freopen("tie.ans", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n + 1; i ++)
        cin >> a[i];
    for (int i = 1; i <= n; i ++)
        cin >> b[i];
    for (int i = 1; i <= n + 1; i ++) {
        ans = 9e18;
        dfs(1, i);
        cout << ans << " ";
    }
	return 0;
}
