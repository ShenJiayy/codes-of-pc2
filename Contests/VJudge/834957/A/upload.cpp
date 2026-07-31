#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e4;
int f[N * 3 + 5];
void init(int n) {
    for (int i = 1; i <= n; i ++)
        f[i] = i;
}
int find(int x) {
    if (f[x] != x)
        f[x] = find(f[x]);
    return f[x];
}
void merge(int x, int y) {
    int ftx = find(x), fty = find(y);
    if (ftx == fty) return ;
    f[ftx] = fty;
}
signed main() {
	int n, T, cnt = 0;
    cin >> n >> T;
    init(n * 3);
    while (T --) {
        int opt, x, y;
        cin >> opt >> x >> y;
        if (x > n || y > n) {
            cnt ++;
            continue;
        }
        if (opt == 1) {
            if (find(x) == find(y + n) || find(x + n) == find(y))
                cnt ++;
            else 
                merge(x, y), 
                merge(x + n, y + n), 
                merge(x + n + n, y + n + n);
        }
        if (opt == 2) {
            if (find(x) == find(y) || find(y) == find(x + n))
                cnt ++;
            else
                merge(x, y + n), 
                merge(x + n, y + n + n), 
                merge(x + n + n, y);
        }
    }
    cout << cnt;
    return 0;
}