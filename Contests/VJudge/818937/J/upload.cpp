#include <bits/stdc++.h>
using namespace std;
#define int __int128
int bsgs(int a, int b, int p) {
    int s = 320000;
    map<int, int> mp;
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
void write(int x) {
    if (x > 9) write(x / 10);
    cout << char(x % 10 + '0');
}
int read() {
    string s;
    cin >> s;
    int res = 0;
    for (char c : s)
        res = res * 10 + c - '0';
    return res;
}
signed main() {
	int a, p;
    a = read(), p = read();
    // 10^x = 9 * a + 1
    int x = bsgs(10, 9 * a + 1, p);
    write(x);
    return 0;
}