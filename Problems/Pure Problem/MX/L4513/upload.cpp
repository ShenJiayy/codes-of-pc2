#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5;
int a[N + 5];
struct Node {
    int val, lv, rv, s;
    Node() {
        val = lv = rv = s = -2e9;
    }
} s[(N << 2) + 5];
Node operator +(Node x, Node y) {
    Node res;
    res.s = x.s + y.s;
    res.lv = max(x.lv, x.s + y.lv);
    res.rv = max(y.rv, y.s + x.rv);
    res.val = max(max(x.val, y.val), x.rv + y.lv);
    return res;
}
void buildAll(int id, int l, int r) {
    // 默认调用build(1, 1, n)
    // 把l~r区间的东西都给他build了（当前Cursor=id）
    // 最好不要传入其他的参数了
    // 要不然会炸
    if (l == r)
        s[id].lv = s[id].rv = s[id].s = s[id].val = a[l];
    else {
        int mid = l + r >> 1;
        buildAll(id * 2, l, mid), buildAll(id * 2 + 1, mid + 1, r);
        s[id] = s[id * 2] + s[id * 2 + 1];
    }
}
void updateAddOne(int id, int l, int r, int p, int d) {
    // 更新单个点
    // 需保证id在l~r区间内
    if (l == r) {
        s[id].lv = s[id].rv = s[id].s = s[id].val = d;
        return ;
    }
    int mid = l + r >> 1;
    if (p <= mid)
        updateAddOne(id * 2, l, mid, p, d);
    else
        updateAddOne(id * 2 + 1, mid + 1, r, p, d);
    s[id] = s[id * 2] + s[id * 2 + 1];
}
Node queryBlock(int id, int l, int r, int ql, int qr) {
    // 设当前在id节点，则函数的返回值为查询l~r对于ql~qr区间和的贡献
    if (ql <= l && r <= qr)
        return s[id]; // 包含[l, r]区间，直接返回
    int mid = l + r >> 1;
    // lson: queryBlock(id * 2, l, mid, ql, qr);
    // rson: queryBlock(id * 2 + 1, mid + 1, r, ql, qr);
    if (qr <= mid)
        return queryBlock(id * 2, l, mid, ql, qr);
    if (ql > mid)
        return queryBlock(id * 2 + 1, mid + 1, r, ql, qr);
    return queryBlock(id * 2, l, mid, ql, qr) + queryBlock(id * 2 + 1, mid + 1, r, ql, qr);
}
signed main() {
    #ifndef ONLINE_JUDGE
        freopen("in.in", "r", stdin);
    #endif
    int n, m;
    scanf("%lld%lld", &n, &m);
    for (int i = 1; i <= n; i ++)
        scanf("%lld", a+i);
    buildAll(1, 1, n);
    while (m --) {
        int opt, x, y;
        scanf("%lld%lld%lld", &opt, &x, &y);
        if (opt == 2)
            updateAddOne(1, 1, n, x, y);
        else {
            if (x > y) swap(x, y);
            printf("%lld\n", queryBlock(1, 1, n, x, y).val);
        }
    }
    return 0;
}