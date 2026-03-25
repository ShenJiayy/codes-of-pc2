#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e4;
int a[N + 5], f[N + 5];
int find(int id) {
    if (f[id] != id) f[id] = find(f[id]);
    return f[id];
}
signed main() {
	int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    for (int i = 1; i <= n; i ++)
        f[i] = i;
    while (q --) {
        int opt;
        cin >> opt;
        if (opt == 1 ) {
            // 补全逻辑
        }
        else {
            int x, y, z;
            cin >> x >> y >> z;
            所以然后







            7
        }
    }
    return 0;
}