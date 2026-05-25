#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 19940417, inv2 = 9970209, inv6 = 3323403;
// a + b mod mod
inline int a(int x, int y) {
    return (x + y) % mod;
}
// a - b mod mod
inline int s(int x, int y) {
    return (a(x, -y) + mod) % mod;
}
// (1 + ... + n) mod mod
inline int gs1(int n) {
    return n * (n + 1) % mod * inv2 % mod;
}
// (1^2 + ... + n^2) mod mod
inline int gs2(int n) {
    return n * (n + 1) % mod * (2 * n + 1) % mod * inv6 % mod;
}
// 左边一个括号
int p1(int n) {
    int ans = 0;
    for (int l = 1, r; l <= n; l = r + 1) {
        r = n / (n / l);
        ans = a(ans, s(gs1(r), gs1(l - 1)) * (n / l) % mod);
    }
    return s(n * n % mod, ans);
}
// 右边那一坨子
int p2(int n, int m) {
    int a1 = 0, a2 = 0;
    for (int l = 1, r; l <= n; l = r + 1) {
        r = min(n / (n / l), m / (m / l));
        a1 = a(a1, s(gs1(r), gs1(l - 1)) * n % mod * (m / l) % mod);
        a1 = a(a1, s(gs1(r), gs1(l - 1)) * m % mod * (n / l) % mod);
        a2 = a(a2, s(gs2(r), gs2(l - 1)) * (n / l) % mod * (m / l) % mod);
    }
    return a(s(n * n % mod * m % mod, a1), a2);
}
signed main() {
    int n, m;
    cin >> n >> m;
    if (n >= m) swap(n, m);
    cout << s(p1(n) * p1(m) % mod, p2(n, m));
    return 0;
}