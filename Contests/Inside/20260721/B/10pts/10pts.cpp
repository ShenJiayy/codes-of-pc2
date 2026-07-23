#include <bits/stdc++.h>
using namespace std;
const int N = 3000;
#define int long long
int a[N + 5];
int n, m, ans;
bool vis[N + 5], revis[N + 5];
void dfs(int id) {
    if (id > n) {
        bool valid = 1;
        for (int l = 1, r = m; r <= n; r ++, l ++) {
            int sum = 0;
            for (int i = l; i <= r; i ++)
                sum += vis[i];
            if (sum > 2)
                valid = 0;
        }
        if (valid) {
            int res = 0;
            for (int i = 1; i <= n; i ++)
                if (vis[i])
                    res += a[i];
            if (ans < res) {
            	ans = res;
            	memcpy(revis, vis, sizeof revis);
			}
        }
        return ;
    }
    vis[id] = 1;
    dfs(id + 1);
    vis[id] = 0;
    dfs(id + 1);
}
signed main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    dfs(1);
    for (int i = 1; i <= n; i ++) cout << revis[i];
}
