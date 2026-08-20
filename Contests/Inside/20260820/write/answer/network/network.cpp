#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5;
struct Edges {
    int u, l, r, w;
} e[N + 5];
namespace bcj {
    int f[N + 5];
    void init(int n) {
        for (int i = 1; i <= N; i ++)
            f[i] = i;
    }
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
}
namespace mst {
    bool cmp(Edges x, Edges y) {
        return x.w < y.w;
    }
    int kruskarl(int n, int m) {
        bcj::init(n);
        sort(e + 1, e + m + 1, cmp);
        int ans = 0, cnt = 0;
        for (int i = 1; i <= m; i ++)
            for (int v = e[i].l; v <= e[i].r; v ++)
                if (bcj::find(e[i].u) != bcj::find(v)) {
                    bcj::merge(e[i].u, v);
                    ans += e[i].w;
                    cnt ++;
                    if (cnt == n - 1)
                        return ans;
                }
        return -1;
    }
}
signed main() {
    freopen("network.in", "r", stdin);
    freopen("network.out", "w", stdout);
    int n1, n2;
    cin >> n1 >> n2;
    int n = n1 + n2, m = 0;
    for (int i = 1; i <= n2; i ++) {
        int l, r, c;
        cin >> l >> r >> c;
        e[++ m] = {i + n1, l, r, c};
    }
    cout << mst::kruskarl(n, m);
    return 0;
}