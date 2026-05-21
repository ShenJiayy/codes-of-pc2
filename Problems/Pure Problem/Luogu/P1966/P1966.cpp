#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e5, MOD = 1e8 - 3;
int n, s[N + 5], c[N + 5];
struct Node {
    int a, i;
    bool operator < (Node b) {
        return a < b.a;
    }
} a[N + 5], b[N + 5];

int lowbit(int x) {
    return x & -x;
}

void AddSum(int p, int d) {
    for (; p <= n; p += lowbit(p))
        s[p] += d;
}

int GetSum(int p) {
    int sum = 0;
    for (; p; p -= lowbit(p))
        sum += s[p];
    return sum;
}

signed main() {
    #ifndef ONLINE_JUDGE
        freopen("inputs\\3.in", "r", stdin);
        // freopen("out.out", "w", stdout);
    #endif
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i].a, a[i].i = i;
    for (int i = 1; i <= n; i ++)
        cin >> b[i].a, b[i].i = i;
    sort(a + 1, a + n + 1);
    sort(b + 1, b + n + 1);
    for (int i = 1; i <= n; i ++)
        c[a[i].i] = b[i].i;
    int ans = 0;
    for (int i = n; i >= 1; i --) {
        AddSum(c[i], 1);
        ans += GetSum(c[i] - 1);
        ans %= MOD;
    }
    cout << ans % MOD;
    return 0;
}