#include <bits/stdc++.h>
using namespace std;
#define int __int128
const int mod = 998244353;
int fp(int a, int b, int p) {
    int ret = 1;
    for (; b; b >>= 1, a = a * a % p)
        if (b & 1)
            ret = ret * a % p;
    return ret;
}
int f(int x) {
    if (x % 2 == 0) return x / 2;
    x = (x + 1) / 2;
    x /= 2, x *= 2;
    return x;
}
void read(int &x) {
    x = 0;
    bool base = 1;
    string s;
    cin >> s;
    if (s[0] == '-') base = -1, s = s.substr(1);
    for (char c : s)
        x = x * 10 + c - '0';
    x *= base;
}
void write(int x) {
    if (x > 9) write(x / 10);
    char c = x % 10 + '0';
    cout << c;
}
signed main() {
	int n;
    read(n);
    int res = fp(n, mod - 2, mod) * f(n) % mod;
    write(res);
    return 0;
}
