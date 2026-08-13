#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5;
struct Node {
    int x, y;
} p[N + 5];
bool cmp(Node x, Node y) {
    if (x.x != y.x)
        return x.x > y.x;
    return x.y > y.y;
}
signed main() {
	int n;
    cin >> n;
    for (int i = 1; i <= n; i ++) {
        int x, e;
        cin >> x >> e;
        p[i].x = e - x;
        p[i].y = x + e;
    }
    sort(p + 1, p + n + 1, cmp);
    int ans = 0, maxn = 9e18;
    for (int i = 1; i <= n; i ++) {
        if (p[i].x > maxn)
            ans ++;
        maxn = max(maxn, p[i].x);
    }
    cout << ans;
    return 0;
}
