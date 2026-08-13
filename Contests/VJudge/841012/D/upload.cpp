#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5;
struct Node {
    int x, y;
} p[N + 5];
bool cmp(Node x, Node y) {
    if (x.y != y.y)
        return x.y > y.y;
    return x.x > y.x;
}
signed main() {
	int n;
    cin >> n;
    for (int i = 1; i <= n; i ++) {
        int x, e;
        cin >> x >> e;
        p[i].x = e - x;
        p[i].y = e + x;
    }
    sort(p + 1, p + n + 1, cmp);
    int ans = 0, maxn = -9e18;
    for (int i = 1; i <= n; i ++) {
        if (p[i].x > maxn)
            ans ++;
        maxn = max(maxn, p[i].x);
    }
    cout << ans;
    return 0;
}
