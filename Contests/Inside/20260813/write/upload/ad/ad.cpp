#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1000;
int e[N + 5], x[N + 5], n, ans = 9e18;
bool vis[N + 5];
void dfs(int id) {
    if (id > n) {
        int cnt = 0;
        for (int i = 1; i <= n; i ++)
            cnt += vis[i];
        int tot = cnt;
        for (int i = 1; i <= n; i ++)
            if (!vis[i])
                for (int j = 1; j <= n; j ++)
                    if (vis[j])
                        if (abs(x[i] - x[j]) <= e[j] - e[i]) {
                            tot ++;
                            break;
                        }
        if (tot == n)
            ans = min(ans, cnt);
        return ;
    }
    vis[id] = 0;
    dfs(id + 1);
    vis[id] = 1;
    dfs(id + 1);
} 
signed main() {
	freopen("ad.in", "r", stdin);
	freopen("ad.out", "w", stdout);
    cin >> n;
    if (n > 16) {
        set<int> st;
        while (n --) {
            int x, e;
            cin >> x >> e;
            st.insert(x);
        }
        cout << st.size();
        return 0;
    }
    for (int i = 1; i <= n; i ++)
        cin >> x[i] >> e[i];
    dfs(1);
    cout << ans;
	return 0;
}
