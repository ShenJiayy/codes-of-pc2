#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 3000;
int a[N + 5], s[N + 5];
int n, m, ans;
void dfs(int id) {
    if (id > n) {
        int res = 0;
        for (int i = 1; i <= n; i ++)
            if (s[i] != s[i - 1])
                res += a[i];
        ans = max(ans, res);
        return ;
    }
    s[id] = s[id - 1] + 1;
    if (s[id] - s[id - m] <= 2)
        dfs(id + 1);
    s[id] --;
    dfs(id + 1);
}
signed main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    dfs(1);
    cout << ans;
}