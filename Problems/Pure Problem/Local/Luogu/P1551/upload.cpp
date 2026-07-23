#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5000;
int f[N + 5];
int find(int id) {
    if (f[id] != id)
        f[id] = find(f[id]);
    return f[id];
}
void merge(int x, int y) {
    int ftx = find(x), fty = find(y);
    if (ftx != fty)
        f[ftx] = fty;
}
signed main() {
	int n, m, T;
    cin >> n >> m >> T;
    for (int i = 1; i <= n; i ++)
        f[i] = i;
    for (int i = 1; i <= m; i ++) {
        int u, v;
        cin >> u >> v;
        merge(u, v);
    }
    while (T --) {
        int u, v;
        cin >> u >> v;
        if (find(u) == find(v))
            puts("Yes");
        else puts("No");
    }
    return 0;
}
