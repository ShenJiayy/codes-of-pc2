#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e7;
int n, a[N + 5], len;
vector<int> v[N + 5];
inline vector<int>::iterator atit(int p) {
    int np = 0;
    for (int i = 0; ; i ++)
        if (np + v[i].size() < p)
            np += v[i].size();
        else
            return v[i].begin() + (p - np - 1);
}
inline int atblock(int p) {
    int np = 0;
    for (int i = 0; ; i ++)
        if (np + v[i].size() < p)
            np += v[i].size();
        else
            return i;
}
inline void rebuild() {
    int curr = 0;
    for (int i = 0; !v[i].empty(); i ++)
        for (int vt : v[i])
            a[++ curr] = vt;
    for (int i = 0; !v[i].empty(); i ++)
        v[i].clear();
    len = sqrt(curr);
    for (int i = 1; i <= curr; i ++)
        v[i / len].emplace_back(a[i]);
}
signed main() {
    scanf("%lld", &n);
    len = sqrt(n);
    for (int i = 1; i <= n; i ++)
        scanf("%lld", a+i), v[i / len].emplace_back(a[i]);
    int optcnt = 0;
    for (int q = 1; q <= n; q ++) {
        int opt;
        scanf("%lld", &opt);
        if (opt == 0) {
            int p, x;
            scanf("%lld%lld", &p, &x);
            v[atblock(p)].emplace(atit(p), x);
            optcnt ++;
            if (optcnt >= 10 * len)
                optcnt = 0, rebuild();
        }
        else {
            int c;
            cin >> c;
            printf("%lld\n", *atit(c));
        }
    }
    return 0;
}