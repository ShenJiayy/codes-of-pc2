#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
mt19937 rnd(random_device{}());
int root = 0, pool = 0;
struct Node {
    int val, pri, num, sz, ls, rs, sum;
} t[N + 5];
int createNode(int x) {
    t[++ pool] = {x, int(rnd()), 1, 1, 0, 0};
    return pool;
}
void update(int x) {
    t[x].sz = t[t[x].ls].sz + t[t[x].rs].sz + t[x].num;
    t[x].sum = t[t[x].ls].sum + t[t[x].rs].sum + t[x].val;
}
void split(int now, int k, int &l, int &r) {
    if (now == 0) {
        l = r = 0;
        return ;
    }
    if (t[t[now].ls].sz + 1 <= k)
        l = now, split(t[now].rs, k - t[t[now].ls].sz - 1, t[now].rs, r);
    else
        r = now, split(t[now].ls, k, l, t[now].ls);
    update(now);
}
int merge(int x, int y) {
    if (x == 0 || y == 0)
        return x + y;
    if (t[x].pri > t[y].pri) {
        t[x].rs = merge(t[x].rs, y);
        update(x);
        return x;
    }
    t[y].ls = merge(t[y].ls, x);
    update(y);
    return y;
}
int main() {
    #ifndef ONLINE_JUDGE
        freopen("in.in", "r", stdin);
    #endif
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) {
        int x;
        cin >> x;
        root = merge(createNode(x));
    }
    while (m --) {
        int opt;
        cin >> opt;
        if (opt == 1) {
            int x, y, k;
            cin >> x >> y >> k;

        }
    }
    return 0;
}