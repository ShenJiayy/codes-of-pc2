#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5;
int a[N + 5][5];
int max(int a, int b, int c) { return max(a, max(b, c)); }
void solve() {
    priority_queue<pair<int, int>> q[5];
    int n, ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i][1] >> a[i][2] >> a[i][3];
        int maxn = max(a[i][1], a[i][2], a[i][3]);
        if (maxn == a[i][1])
            q[1].push({max(a[i][2] - maxn, a[i][3] - maxn), i});
        else if (maxn == a[i][2])
            q[2].push({max(a[i][1] - maxn, a[i][3] - maxn), i});
        else
            q[3].push({max(a[i][1] - maxn, a[i][2] - maxn), i});
        ans += maxn;
    }
    for (int i = 1; i <= 3; i ++)
        while (q[i].size() > n / 2) {
            auto t = q[i].top();
            q[i].pop();
            ans += t.first;
        }
    cout << ans << endl;
}
signed main() {
	int T;
    cin >> T;
    while (T --) 
        solve();
    return 0;
}
