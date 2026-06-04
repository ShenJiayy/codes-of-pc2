#include <bits/stdc++.h>
using namespace std;
#define int __int128
const int mod = 998244353;
int a[25];
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}
void read(int& x) {
    string s;
    cin >> s;
    x = 0;
    for (char c : s)
        x = x * 10 + c - '0';
}
void write(int x) {
    if (x > 9)
        write(x / 10);
    cout << char(x % 10 + '0');
}
signed main() {
	int T;
    read(T);
    a[0] = 1;
    for (int i = 1; i <= 20; i ++)
        a[i] = a[i - 1] * 10;
    while (T --) {
        int n, m;
        read(n), read(m);
        int cnt = 0;
        for (int k = 1; k <= 20; k ++) {
            int l = a[k - 1], r = min(a[k], n + 1);
            if (l >= r) break;
            int g = gcd(a[k] - 1, m);
            cnt += (n / (m / g)) % mod * (r - l) % mod, cnt %= mod;
        }
        write(cnt);
        cout << endl;
    }
    return 0;
}