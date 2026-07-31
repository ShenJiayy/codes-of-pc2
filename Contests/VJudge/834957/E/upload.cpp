#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5;
struct Node {
    int llen, rlen, ans;
    char lchr, rchr;
} t[(N << 2) + 5];
void merge(int id, int l, int r) {
    int lft = id << 1, rgt = id << 1 | 1, mid = l + r >> 1;
    t[id].lchr = t[lft].lchr;
    t[id].rchr = t[rgt].rchr;
    t[id].ans = max(t[lft].ans, t[rgt].ans);
    if (t[lft].rchr != t[rgt].lchr)
        t[id].ans = max(t[id].ans, t[lft].rlen + t[rgt].llen);
    t[id].llen = t[lft].llen;
    if (t[lft].llen == mid - l + 1 && t[lft].rchr != t[rgt].lchr)
        t[id].llen += t[rgt].llen;
    t[id].rlen = t[rgt].rlen;
    if (t[rgt].rlen == r - mid && t[rgt].lchr != t[lft].rchr)
        t[id].rlen += t[lft].rlen;
}
void build(int id, int l, int r) {
    if (l == r) {
        t[id].llen = t[id].rlen = t[id].ans = 1;
        t[id].lchr = t[id].rchr = 'L';
        return ;
    }
    int lft = id << 1, rgt = id << 1 | 1, mid = l + r >> 1;
    build(lft, l, mid);
    build(rgt, mid + 1, r);
    merge(id, l, r);
}
void update(int id, int l, int r, int orgid) {
    if (l == r) {
        if (t[id].lchr == 'L')
            t[id].lchr = t[id].rchr = 'R';
        else
            t[id].lchr = t[id].rchr = 'L';
        return ;
    }
    int lft = id << 1, rgt = id << 1 | 1, mid = l + r >> 1;
    if (orgid <= mid)
        update(lft, l, mid, orgid);
    else
        update(rgt, mid + 1, r, orgid);
    merge(id, l, r);
}
signed main() {
	int n, T;
    cin >> n >> T;
    build(1, 1, n);
    while (T --) {
        int p;
        cin >> p;
        update(1, 1, n, p);
        cout << t[1].ans << endl;
    }
    return 0;
}
