#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 2e5;
int c[N + 5], n, s, t;

int lowbit(int x) {
    return x & -x;
}

int cal(int x) {
    if (x > 0)
        return -s * x;
    return -t * x;
}

void SetNum(int p, int d) {
    for (; p <= n; p += lowbit(p))
        c[p] += d;
}

int GetSum(int p) {
    int sum = 0;
    for (; p; p -= lowbit(p))
        sum += c[p];
    return sum;
}

signed main() {
    #ifndef ONLINE_JUDGE
        freopen("in.in", "r", stdin);
        // freopen("out.out", "w", stdout);
    #endif
    int q, ans = 0;
    cin >> n >> q >> s >> t;
    int prv;
    cin >> prv;
    ans += cal(prv); // 木有撒用
    for (int i = 1; i <= n; i ++) {
        int now;
        cin >> now;
        ans += cal(now - prv);
        SetNum(i, now - prv);
        prv = now;
    }
    while (q --) {
        int x, y, z;
        cin >> x >> y >> z;
        int prx = GetSum(x) - GetSum(x - 1), pry = GetSum(y + 1) - GetSum(y);
        SetNum(x, z);
        if (y != n) SetNum(y + 1, -z);
        int nwx = GetSum(x) - GetSum(x - 1), nwy = GetSum(y + 1) - GetSum(y);
        ans -= cal(prx);
        ans += cal(nwx);
        if (y != n) ans -= cal(pry), ans += cal(nwy);
        printf("%lld\n", ans);
    }
    return 0;
}