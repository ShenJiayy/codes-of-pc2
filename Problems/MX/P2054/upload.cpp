#include <bits/stdc++.h>
using namespace std;
#define int long long
pair<int, pair<int, int>> exgcd(int a, int b) {
    if (b == 0) 
        return {a, {1, 0}};
    int gcd, x1, y1;
    auto ret = exgcd(b, a % b);
    gcd = ret.first, x1 = ret.second.first, y1 = ret.second.second;
    int x = y1, y = x1 - a / b * y1;
    return {gcd, {x, y}};
}
int fm(int a, int b, int p) {
    int ret = 0;
    for (; b; b >>= 1, a = a * 2 % p)
        if (b & 1)
            ret += a, ret %= p;
    return ret;
}
int fp(int a, int b, int p) {
    int ret = 1;
    for (; b; b >>= 1, a = fm(a, a, p))
        if (b & 1)
            ret = fm(ret, a, p);
    return ret;
}

signed main() {
	int n, m, l;
    cin >> n >> m >> l;
    auto ret = exgcd(2, n + 1).second;
    int x = ret.first, y = ret.second;
    int b = n + 1;
    x = (x % b + b) % b;
    x = fp(x, m, b);
    cout << fm(l, x, b);
    return 0;
}