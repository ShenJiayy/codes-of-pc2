#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2000, mod = 998244353, M = N * N;
int a[N + 5], b[N + 5];
int fp(int a, int b, int p) {
    int ret = 1;
    for (; b; b >>= 1, a = a * a % p)
        if (b & 1)
            ret = ret * a % p;
    return ret;
}
const int inv2 = fp(2, mod - 2, mod);
signed main() {
	int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
        cin >> a[i], a[i] = a[i - 1] + a[i];
    for (int i = 1; i <= m; i ++)
        cin >> b[i], b[i] = b[i - 1] + b[i];
    int cnt1 = n * (n + 1) % mod * inv2 % mod * m % mod * (m + 1) % mod * inv2 % mod, cnt2 = 0;
    vector<int> p, q;
    for (int i = 0; i <= n; i ++)
        for (int j = 0; j < i; j ++)
            p.push_back(a[i] - a[j]);
    for (int i = 0; i <= m; i ++)
        for (int j = 0; j < i; j ++)
            q.push_back(b[i] - b[j]);
    sort(p.begin(), p.end());
    sort(q.begin(), q.end());
    int j = 0;
    for (int i = 0; i < p.size(); i ++) {
        while (p[i] > q[j] && j < q.size())
            j ++;
        cnt2 += j, cnt2 %= mod;
    }
    int invp = fp(cnt1, mod - 2, mod);
    int ans = invp * cnt2 % mod;
    cout << ans;
    return 0;
}