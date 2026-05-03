#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 300000;
int a[N + 5], n, blk[N + 5], lazy[N + 5], len, s[N + 5];
int read() {
    int x=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
    return x*f;
}
void add(int l, int r, int c) {
    if (blk[l] == blk[r]) {
        for (int i = l; i <= r; i ++)
            a[i] += c;
        s[blk[l]] += c * (r - l + 1);
    }
    else {
        for (int i = l; i <= blk[l] * len; i ++)
            a[i] += c;
        s[blk[l]] += c * (blk[l] * len - l + 1);
        for (int i = (blk[r] - 1) * len + 1; i <= r; i ++)
            a[i] += c;
        s[blk[r]] += c * (r - ((blk[r] - 1) * len + 1) + 1);
        for (int i = blk[l] + 1; i < blk[r]; i ++)
            lazy[i] += c;
    }
}
int query(int l, int r, int p) {
    int ans = 0;
    if (blk[l] == blk[r]) {
        for (int i = l; i <= r; i ++)
            ans += a[i] + lazy[blk[i]];
    }
    else {
        for (int i = l; i <= blk[l] * len; i ++)
            ans += a[i] + lazy[blk[l]];
        for (int i = (blk[r] - 1) * len + 1; i <= r; i ++)
            ans += a[i] + lazy[blk[r]];
        for (int i = blk[l] + 1; i < blk[r]; i ++)
            ans += lazy[i] * len + s[i];
    }
    return (ans % p + p) % p;
}
signed main() {
    #ifndef ONLINE_JUDGE
        freopen("in.in", "r", stdin);
    #endif
    // Write here.
    n = read();
    len = sqrt(n);
    for (int i = 1; i <= n; i ++)
        a[i] = read(), blk[i] = (i - 1) / len + 1, s[blk[i]] += a[i];
    for (int i = 1; i <= n; i ++) {
        int opt = read(), l = read(), r = read(), c = read();
        if (opt == 0) 
            add(l, r, c);
        else
            printf("%lld\n", query(l, r, c + 1));
    }
    return 0;
}