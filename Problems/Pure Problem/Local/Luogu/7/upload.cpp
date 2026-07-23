#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5;
int f[N + 5], sz[N + 5];
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
	int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
        f[i] = i;
    for (int i = 1; i <= m; i ++) {
        int u, v;
        cin >> u >> v;
        merge(u, v);
    }
    int cnt = 0;
    for (int i = 1; i <= n; i ++)
        sz[find(i)] ++;
    for (int i = 1; i <= n; i ++) 
        cnt += n - sz[find(i)];
    cout << cnt / 2;
    return 0;
}
