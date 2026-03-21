#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5;
int a[N + 5];
signed main() {
    int n, k, ans = 9e18;
    cin >> n >> k;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    for (int i = 1; i <= n; i ++)
        a[i] %= k;
    sort(a + 1, a + n + 1);
    deque<int> dq;
    for (int i = 1; i <= n; i ++)
        dq.push_back(a[i]);
    for (int i = 1; i <= n; i ++) {
        dq.push_back(dq.front() + k);
        dq.pop_front();
        ans = min(ans, dq.back() - dq.front());
    }
    cout << ans;
    return 0;
}