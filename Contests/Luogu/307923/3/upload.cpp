#include <bits/stdc++.h>
using namespace std;
#define int long long
int read()
{
    int x=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
    return x*f;
}
const int N = 3e5;
int a[N + 5], blk[N + 5], lazy[N + 5], len;
vector<int> v[N + 5];
void update(int x) {
    v[x].clear();
    for (int i = (x - 1) * len + 1; i <= x * len; i ++)
        v[x].emplace_back(a[i]);
    sort(v[x].begin(), v[x].end());
}
void add(int l, int r, int k) {
    if (blk[l] == blk[r]) {
        for (int i = l; i <= r; i ++)
            a[i] += k;
        update(blk[l]);
    }
    else {
        for (int i = l; i <= len * blk[l]; i ++)
            a[i] += k;
        update(blk[l]);
        for (int i = len * (blk[r] - 1) + 1; i <= r; i ++)
            a[i] += k;
        update(blk[r]);
        for (int i = blk[l] + 1; i < blk[r]; i ++)
            lazy[i] += k;
    }
}
int query(int l, int r, int k)  {
    int ans = -9e18;
    if (blk[l] == blk[r]) {
        for (int i = l; i <= r; i ++)
            if (a[i] + lazy[blk[l]] < k)
                ans = max(ans, a[i] + lazy[blk[l]]);
    }
    else {
        for (int i = l; i <= len * blk[l]; i ++)
            if (a[i] + lazy[blk[l]] < k)
                ans = max(ans, a[i] + lazy[blk[l]]);
        for (int i = len * (blk[r] - 1) + 1; i <= r; i ++)
            if (a[i] + lazy[blk[r]] < k)
                ans = max(ans, a[i] + lazy[blk[r]]);
        for (int i = blk[l] + 1; i < blk[r]; i ++) {
            int idx = lower_bound(v[i].begin(), v[i].end(), k - lazy[i]) - v[i].begin();
            if (idx) ans = max(ans, v[i][idx - 1] + lazy[i]);
        }
    }
    if (ans == -9e18) return -1;
    return ans;
}
signed main() {
    #ifndef ONLINE_JUDGE
        freopen("in.in", "r", stdin);
    #endif
    int n = read();
    len = sqrt(n);
    for (int i = 1; i <= n; i ++) {
        a[i] = read();
        blk[i] = (i - 1) / len + 1;
        v[blk[i]].emplace_back(a[i]);
    }
    for (int i = 1; i <= blk[n]; i ++)
        sort(v[i].begin(), v[i].end());
    for (int q = 1; q <= n; q ++) {
        int opt = read(), l = read(), r = read(), c = read();
        if (opt == 0) add(l, r, c);
        else printf("%lld\n", query(l, r, c));
    }
    return 0;
}