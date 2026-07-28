#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1000;
struct Node {
    int x, y, r;
} a[N + 5];
bool soff(int i, int j) {
    return (a[i].x - a[j].x) * (a[i].x - a[j].x) + (a[i].y - a[j].y) * (a[i].y - a[j].y) <= (a[i].r + a[j].r) * (a[i].r + a[j].r);
}
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
	int n;
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i].x >> a[i].y >> a[i].r, f[i] = i;
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= n; j ++) 
            if (soff(i, j))
                merge(i, j);
    for (int i = 1; i <= n; i ++)
        sz[find(i)] ++;
    int maxn = 0;
    for (int i = 1; i <= n; i ++)
        maxn = max(maxn, sz[i]);
    cout << maxn;
    return 0;
}
