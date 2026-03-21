#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5, mod = 1e9 + 7;
int f[N + 5], rd[N + 5];
vector<pair<int, int>> edge;
map<pair<int, int>, bool> mp;
int find(int x) {
    if (f[x] != x)
        f[x] = find(f[x]);
    return f[x];
}
signed main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
        f[i] = i;
    for (int i = 1; i <= m; i ++) {
        int x, y;
        cin >> x >> y;
        if (mp[{x, y}] == 1) continue ;
        mp[{x, y}] = 1;
        edge.push_back({x, y});
    }
    bool valid = 1;
    for (auto kv : edge) {
        int x = kv.first, y = kv.second;
        int ftx = find(x), fty = find(y);
        if (ftx == fty)
            valid = 0;
        rd[y] ++;
        if (rd[y] > 1)
            valid = 0;
        f[ftx] = fty;
    }
    if (valid == 0) {
        cout << 0;
        return 0;
    }
    int cnt = 0;
    for (int i = 1; i <= n; i ++)
        cnt += find(i) == i;
    int ans = 1;
    for (int i = 1; i <= cnt; i ++)
        ans = ans * i % mod;
    cout << ans;
    return 0;
}