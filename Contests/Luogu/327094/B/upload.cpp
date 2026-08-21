#include <bits/stdc++.h>
using namespace std;
#define int long long
struct frac {
    int p, q;
    void operator = (frac x) {
        p = x.p, q = x.q;
    }
};
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
frac tomini(frac x) {
    int g = gcd(x.p, x.q);
    return {x.p / g, x.q / g};
}
bool operator < (frac x, frac y) {
    return x.p * y.q < y.p * x.q;
}





const int N = 1e6;
int a[N + 5], s[N + 5];
int lft[N + 5], rgt[N + 5];
signed main() {

    // 恭喜 获得 头图 一个
    // manba out!!!
    
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i], s[i] = s[i - 1] + a[i];
    int lst = 1;
    for (int i = 1; i <= n; i ++) {
        if (a[i] == 0) continue;
        lft[i] = i - lst;
        lst = i + 1;
    }
    lst = n;
    for (int i = n; i >= 1; i --) {
        if (a[i] == 0) continue;
        rgt[i] = lst - i;
        lst = i - 1;
    }
    frac ans = {9000000000000, 1};
    for (int i = 1; i <= n; i ++) {
        if (a[i] == 0) continue;
        int sum = s[i + rgt[i]] - s[i - lft[i] - 1];
        int cnt = rgt[i] + lft[i] + 1;
        frac now = {sum, cnt};
        if (now < ans)
            ans = now;
    }
    ans = tomini(ans);
    cout << ans.p << " " << ans.q;
    return 0;
}