#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5;
int f[N + 5], dep[N + 5];
int find(int x) {
    if (f[x] == x) return x;
    int ft = f[x];
    f[x] = find(f[x]);
    dep[x] += dep[ft];
    return f[x];
}
signed main() {
	int n, m, T;
    scanf("%lld%lld%lld", &n, &m, &T);
    for (int i = 1; i <= n; i ++) f[i] = i;
    for (int i = 1; i <= m; i ++) {
        int l, r, s;
        scanf("%lld%lld%lld", &l, &r, &s);
        l --;
        int ftx = find(l), fty = find(r);
        if (ftx != fty) {
            f[ftx] = fty;
            dep[ftx] = dep[r] - s - dep[l]; // This one is copied.
        }
    }
    while (T --) {
        int l, r;
        scanf("%lld%lld", &l, &r);
        l --;
        int ftx = find(l), fty = find(r);
        if (ftx != fty)
            printf("UNKNOWN\n");
        else
            printf("%lld\n", dep[r] - dep[l]);
    }
    return 0;
}