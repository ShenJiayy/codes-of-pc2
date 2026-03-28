#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5;
int a[N + 5], len, blk[N + 5], lazy[N + 5];
vector<int> st[N + 5];
void update(int x) { // Update Block {x}
    st[x].clear();
    for (int i = (x - 1) * len + 1; i <= x * len; i ++)
        st[x].push_back(a[i]);
    sort(st[x].begin(), st[x].end());
} 
void add(int l, int r, int k) {
    if (blk[l] == blk[r]) {
        for (int i = l; i <= r; i ++)
            a[i] += k;
        update(blk[l]);
    }
    else {
        for (int i = l; i <= blk[l] * len; i ++)
            a[i] += k;
        update(blk[l]);
        for (int i = (blk[r] - 1) * len + 1; i <= r; i ++)
            a[i] += k;
        update(blk[r]);
        for (int i = blk[l] + 1; i <= blk[r] - 1; i ++)
            lazy[i] += k;
    }
}
int query(int l, int r, int x) {
    int ans = 0;
    if (blk[l] == blk[r]) {
        for (int i = l; i <= r; i ++)
            if (a[i] < x)
                ans ++;
    }
    else {
        for (int i = l; i <= blk[l] * len; i ++)
            if (a[i] < x)
                ans ++;
        for (int i = (blk[r] - 1) * len + 1; i <= r; i ++)
            if (a[i] < x)
                ans ++;
        for (int i = blk[l] + 1; i < blk[r]; i ++)
            ans += lower_bound(st[i].begin(
                .'
                '
            ), st[i].end(), x - lazy[i]) - st[i].begin();
    }
    return ans;
}
signed main() {
    #ifndef ONLINE_JUDGE
        freopen("in.in", "r", stdin);
    #endif
    int n;
    cin >> n;
    len = sqrt(n);
    for (int i = 1; i <= n; i ++)
        cin >> a[i], blk[a[i]] = (i - 1) / len + 1, st[blk[i]].push_back(a[i]);
    for (int i = 1; i <= blk[n]; i ++)
        sort(st[i].begin(), st[i].end());
    for (int i = 1; i <= n; i ++) {
        int opt, l, r, k;
        cin >> opt >> l >> r >> k;
        if (opt == 0) {
            add(l, r, k);
        }
        else {
            cout << query(l, r, k * k) << endl;
        }
    }
    return 0;
}