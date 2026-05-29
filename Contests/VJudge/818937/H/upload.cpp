#include <bits/stdc++.h>
using namespace std;
#define int long long
int fp(int a, int b, int p) {
    int ret = 1;
    for (; b; b >>= 1, a = a * a % p)
        if (b & 1)
            ret = ret * a % p;
    return ret;
}
pair<int, pair<int, int>> exgcd(int a, int b) {
    if (b == 0)
        return {a, {1, 0}};
    auto gr = exgcd(b, a % b);
    int g = gr.first, x1 = gr.second.first, y1 = gr.second.second;
    int x = y1, y = x1 - a / b * y1;
    return {g, {x, y}};
}
int bsgs(int a, int b, int p) {
    int s = sqrt(p) + 1;
    unordered_map<int, int> mp;
    for (int i = 1, ax = a * b % p; i <= s; i ++, ax = ax * a % p)
        mp[ax % p] = i;
    int t = 1;
    for (int i = 1; i <= s; i ++)
        t *= a, t %= p;
    for (int i = 1, bx = t; i <= s; i ++, bx = bx * t % p)
        if (mp[bx])
            return i * s - mp[bx];
    return -1;
}
int solve(int opt, int a, int b, int p) {
    if (opt == 1)
        return fp(a, b, p);
    if (opt == 2) {
        auto gr = exgcd(a, p);
        int g = gr.first, x = gr.second.first;
        if (b % g) return -1;
        x *= b / g;
        x %= p, x += p, x %= p;
        return x;
    }
    a %= p, b %= p;
    if (a == 0) {
        if (b == 0) return 1;
        if (b == 1) return 0;
        return -1;
    }
    int res = bsgs(a, b, p);
    return res;
}
signed main() {
    int T, k;
    cin >> T >> k;
    while (T --) {
        int a, b, p;
        cin >> a >> b >> p;
        int res = solve(k, a, b, p);
        if (res == -1)
            cout << "Orz, I cannot find x!\n";
        else
            cout << res << endl;
    }
    return 0;
}
