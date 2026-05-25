#include <bits/stdc++.h>
using namespace std;
#define int long long
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
signed main() {
	int a, b, p;
    cin >> p >> a >> b;
    int ans = bsgs(a, b, p);
    if (ans == -1) cout << "no solution";
    else cout << ans;
    return 0;
}
