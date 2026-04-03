#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5, mod = 1e9 + 7;
int n, a[N + 5], b[N + 5], cnt;
bool vis[N + 5];
bool check(int k, int c[]) {
    if (k == 0) return 0;
    int p = 0;
    for (int i = 1; i <= k; i ++)
        p += c[i] * (c[i] - 1) / 2;
    int gcd = c[1];
    for (int i = 1; i <= k; i ++)
        gcd = __gcd(gcd, c[i]);
    return -p % gcd == 0;
}
void dfs(int id) {
    if (id > n) {
        int cur = 0;
        for (int i = 1; i <= n; i ++)
            if (vis[i])
                b[++ cur] = a[i];
        cnt += check(cur, b);
        cnt %= mod;
        return ;
    }
    vis[id] = 0;
    dfs(id + 1);
    vis[id] = 1;
    dfs(id + 1);
}
signed main() {
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    dfs(1);
    cout << cnt;
    return 0;
}