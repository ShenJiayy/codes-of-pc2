#include <bits/stdc++.h>
using namespace std;
#define int __int128
const int N = 1e5, mod = 998244353;
vector<int> g[N + 5];
// 令 a[i] 表示从 i 开始的路径长度和， b[i] 表示从 i 开始的路径条数。
int a[N + 5], b[N + 5];
bool vis[N + 5];
void dfs(int id) {
    if (vis[id]) return ;
    vis[id] = 1;
    b[id] = 1, a[id] = 0;
    for (int nxt : g[id]) {
        dfs(nxt);
        b[id] += b[nxt], b[id] %= mod;
        a[id] += a[nxt] + b[nxt], a[id] %= mod;
    }
}
int fp(int a, int b, int p) {
    int ret = 1;
    for (; b; b >>= 1, a = a * a % p)
        if (b & 1)
            ret = ret * a % p;
    return ret;
}
int read() {
    string s;
    cin >> s;
    int ans = 0;
    for (char c : s)
        ans = ans * 10 + c - '0';
    return ans;
}
void write(int x) {
    if (x > 9) write(x / 10);
    char c = x % 10 + '0';
    cout << c;
}
signed main() {
	int n = read(), m = read();
    for (int i = 1; i <= m; i ++) {
        int u = read(), v = read();
        g[u].push_back(v);
    }
    for (int i = 1; i <= n; i ++)
        if (vis[i] == 0)
            dfs(i);
    int p = 0, q = 0;
    // 答案是 q / p
    for (int i = 1; i <= n; i ++)
        q += a[i], p += b[i];
    p = fp(p, mod - 2, mod);
    q *= p, q %= mod;
    write(q);
    return 0; 
}
