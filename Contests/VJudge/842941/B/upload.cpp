#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5;
struct Edges {
    int u, l, r, w;
} e[N + 5];
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
bool cmp(Edges x, Edges y) {
    return x.w < y.w;
}
signed main() {
    int n, m;
    cin >> n >> m;
    init(n);
    for (int i = 1; i <= m; i ++) {
        int l, r, c;
        cin >> l >> r >> c;
        e[i] = {i + n, l, r, c};
    }
    sort(e + 1, e + m + 1, cmp);
    int ans = 0;
    for (int i = 1; i <= m; i ++) {
        int l = e[i].l, r = e[i].r;
        int cnt = 0;
        vector<int> q;
        while (1) {
            l = find(l);
            cnt ++;
            if (l >= r)
                break;
            q.push_back(l);
            l ++;
        }
        for (int val : q)
            f[val] = l;
        ans += cnt * e[i].w;
    }
    if (find(1) != n)
        puts("-1");
    else cout << ans;
    return 0;
}
