#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5;
struct Node {
    int p, t;
} a[N + 5];
int dp[N + 5], curr;
bool cmp(Node x, Node y) {
    if (x.p != y.p) return x.p < y.p;
    return x.t < y.t;
}
signed main() {
	int n;
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i].p >> a[i].t, a[i].t -= a[i].p;
    sort(a + 1, a + n + 1, cmp);
    for (int i = 1; i <= n; i ++) {
        if (a[i].t < 0) continue;
        if (curr == 0 || a[i].t >= dp[curr])
            dp[++ curr] = a[i].t;
        else {
            int ptr = upper_bound(dp + 1, dp + curr + 1, a[i].t) - dp;
            dp[ptr] = a[i].t;
        }
    }
    cout << curr;
    return 0;
}