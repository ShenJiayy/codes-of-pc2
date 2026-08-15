#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2000;
char s[N + 5];
int n, m, ans;
bool vis[N + 5];
void dfs(int id, int siz) {
    if (id > n) {
        if (siz != m * 3) return ;
        string res;
        int stp = 0;
        for (int i = 1; i <= n; i ++)
            if (vis[i])
                res += s[i];
        int f1 = -1, l1 = -1;
        for (int i = 1; i <= n; i ++)
            if (vis[i]) {
                f1 = i;
                break;
            }
        for (int i = n; i >= 1; i --)
            if (vis[i]) {
                l1 = i;
                break;
            }
        for (int i = f1; i <= l1; i ++)
            if (!vis[i])
                stp ++;
        for (int i = 0; i < m; i ++)
            if (res[i] != 'J')
                return ;
        for (int i = m; i < m * 2; i ++)
            if (res[i] != 'O')
                return ;
        for (int i = m * 2; i < m * 3; i ++)
            if (res[i] != 'I')
                return ;
        ans = min(ans, stp);
        return ;
    }
    vis[id] = 0;
    dfs(id + 1, siz);
    if (siz < m * 3) {
        vis[id] = 1;
        dfs(id + 1, siz + 1);
    }
}
signed main() {
	freopen("jjooii.in", "r", stdin);
	freopen("jjooii.out", "w", stdout);
    scanf("%lld%lld", &n, &m);
    scanf("%s", s + 1);
    ans = 9e18;
    dfs(1, 0);
    if (ans == 9e18)
        puts("-1");
    else cout << ans;
	return 0;
}