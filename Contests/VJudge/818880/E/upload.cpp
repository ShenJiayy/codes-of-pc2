#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 3e5, M = 6e5;
int f[M + 5], size[M + 5];
int find(int id) {
    if (f[id] != id) 
        f[id] = find(f[id]);
    return f[id];
}
void init() {
    for (int i = 1; i <= M; i ++)
        f[i] = i;
}
void merge(int x, int y) {
    int ftx = find(x), fty = find(y);
    if (ftx != fty)
        f[ftx] = fty;
}
signed main() {
	int n, m;
    cin >> n >> m;
    init();
    for (int i = 1; i <= m; i ++) {
        int u, v;
        cin >> u >> v;
        merge(v + n, u);
    }
    for (int i = 1; i <= n; i ++) 
        size[find(i)] ++;
    for (int i = n + 1; i <= 2 * n; i ++)
        if (find(i) != f[i - n] && f[i] != i)
            size[find(i)] ++;
    for (int i = 1; i <= n; i ++)
        cout << n - size[find(i)] << endl;
    return 0;
}
