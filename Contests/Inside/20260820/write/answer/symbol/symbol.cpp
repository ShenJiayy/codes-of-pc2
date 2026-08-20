#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1000;
char inp[N + 5];
int mod, n;
bool vis[N + 5];
int a, b, c, d;
void dfs(int id) {
    if (id >= n) {
        int val = 1, cnt = 0, num = 0;
        for (int i = 1; i < n; i ++) {
            num = num * 10 + inp[i] - '0', num %= mod;
            if (vis[i])
                cnt ++, val *= num, num = 0, val %= mod;
        }
        num = num * 10 + inp[n] - '0', num %= mod;
        val *= num, val %= mod;
        if (val < a || val == a && cnt < b)
            a = val, b = cnt;
        if (val > c || val == c && cnt < d)
            c = val, d = cnt;
        return ;
    }
    vis[id] = 1;
    dfs(id + 1);
    vis[id] = 0;
    dfs(id + 1);
}
signed solve() {
    scanf("%s", inp + 1);
    n = strlen(inp + 1);
    scanf("%lld", &mod);
    a = 9e18;
    b = c = d = 0;
    dfs(1);
    printf("%lld %lld %lld %lld\n", a, b, c, d);
    return 0;
}
signed main() {
    freopen("symbol.in", "r", stdin);
    freopen("symbol.out", "w", stdout);
    int T;
    scanf("%lld", &T);
    while (T --) 
        solve();
    return 0;
}
