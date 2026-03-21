#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e4;
int f[N * 3 + 5];
int find(int x) {
    if (f[x] != x)
        f[x] = find(f[x]);
    return f[x];
}
void merge(int x, int y) {
    int ftx = find(x), fty = find(y);
    if (ftx != fty)
        f[ftx] = fty;
}
signed main() {
    #ifndef ONLINE_JUDGE
        freopen("in.in", "r", stdin);
    #endif
    int n, k;
    cin >> n >> k;
    int fake = 0;
    for (int i = 1; i <= 3 * n; i ++)
        f[i] = i;
    while (k --) {
        int opt, x, y;
        cin >> opt >> x >> y;
        if (x > n || y > n) {
            fake ++;
            continue;
        }
        if (opt == 1) {
            if (find(x + n) == find(y) || find(x) == find(y + n))
                fake ++;
            else
                merge(x, y), merge(x + n, y + n), merge(x + 2 * n, y + 2 * n);
        }
        else {
            if (find(x) == find(y) || find(x) == find(y + n))
                fake ++;
            else
                merge(x + n, y), merge(x + 2 * n, y + n), merge(x, y + 2 * n); 
        }
    }
    cout << fake;
    return 0;
}