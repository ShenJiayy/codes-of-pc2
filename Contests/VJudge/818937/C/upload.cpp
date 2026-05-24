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
int gs1(int n) {
    return n * (n + 1) % mod * inv2 % mod;
}
// (1^2 + ... + n^2) mod mod
int gs2(int n) {
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

signed main() {
    int n, m;
    cin >> n >> m;
    
    return 0;
}