#include <bits/stdc++.h>
using namespace std;
#define int long long
const int M = 2e5;
struct Node {
    int a, b;
} a[M + 5];
bool cmp(Node x, Node y) {
    return x.a - x.b < y.a - y.b;
}
signed main() {
	int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
        cin >> a[i].a >> a[i].b;
    sort(a + 1, a + m + 1, cmp);
    int ans = 0;
    for (int i = 1; i <= n; i ++) {
        int k = max(0ll, (n - a[i].b) / (a[i].a - a[i].b));
        ans += k;
        n -= k * (a[i].a - a[i].b);
    }
    cout << ans;
    return 0;
}
