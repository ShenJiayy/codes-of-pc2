#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5, M = 4e5;
int a[N + 5];
struct Query {
    int l, r, x, id;
} qs[N + 5];
bool cmp(Query x, Query y) {
    return x.x > y.x;
}
vector<int> addons[M + 5];
int ans[N + 5], vals[N + 5];

struct Node {
    int l, r, ans;
    Node() { l = r = ans = 0; }
    Node(int x, int y, int z) { l = x, r = y, ans = z; }
    void operator = (int x) {
        l = r = ans = x;
    }
} t[(N << 2) + 5];
Node operator + (Node x, Node y) {
    return {x.l, y.r, x.ans + y.ans - (x.r && x.r == y.l)};
}
void update(int id, int l, int r, int p) {
    if (l == r) {
        t[id] = 1;
        return ;
    }
    int mid = l + r >> 1, ls = id << 1, rs = id << 1 | 1;
    if (p <= mid)
        update(ls, l, mid, p);
    else update(rs, mid + 1, r, p);
    t[id] = t[ls] + t[rs];
}
Node query(int id, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) 
        return t[id];
    int mid = l + r >> 1, ls = id << 1, rs = id << 1 | 1;
    if (ql <= mid && mid + 1 <= qr)
        return query(ls, l, mid, ql, qr) + query(rs, mid + 1, r, ql, qr);
    if (ql <= mid)
        return query(ls, l, mid, ql, qr);
    if (mid + 1 <= qr)
        return query(rs, mid + 1, r, ql, qr);
    return {-1, -1, -1};
}
signed main() {
    int n, T;
    cin >> n >> T;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    for (int t = 1; t <= T; t ++)
        cin >> qs[t].l >> qs[t].r >> qs[t].x, qs[t].id = t, vals[t] = qs[t].x;
    sort(qs + 1, qs + T + 1, cmp);
    sort(vals + 1, vals + T + 1, greater<int>());
    for (int i = 1; i <= n; i ++)
        addons[upper_bound(vals + 1, vals + T + 1, a[i], greater<int>()) - vals].push_back(i);
    int curr = 0;
    for (int t = 1; t <= T; t ++) {
        for (int nxt : addons[++ curr])
            update(1, 1, n, nxt);
        ans[qs[t].id] = query(1, 1, n, qs[t].l, qs[t].r).ans;
    }
    for (int i = 1; i <= T; i ++)
        cout << ans[i] << endl;
    return 0;
}
