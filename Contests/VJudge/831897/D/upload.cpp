#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5;
int a[N + 5], f[N + 5];
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
	int n, T;
    cin >> n >> T;
    for (int i = 1; i <= n; i ++)
        f[i] = a[i] = i;
    while (T --) {
        int opt;
        cin >> opt;
        if (opt == 1) {
            int x;
            cin >> x;
            int minn = 9e18, maxn = 0;
            for (int i = 1; i <= n; i ++)
                if (find(i) == find(x))
                    minn = min(minn, a[i]), maxn = max(maxn, a[i]);
            cout << minn << " " << maxn << endl;
        }
        else {
            int l, r, len;
            cin >> l >> r >> len;
            for (int i = 0; i < len; i ++)
                merge(l + i, r + i);
        }
    }
    return 0;
}
