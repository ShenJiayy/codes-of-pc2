#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int n;
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 1; i <= n; i ++) {
        int x;
        cin >> x;
        q.push(x);
    }
    int ans = 0;
    while (q.size() >= 2) {
        int t1 = q.top();
        q.pop();
        int t2 = q.top();
        q.pop();
        ans += t1 + t2;
        q.push(t1 + t2);
    }
    cout << ans;
    return 0;
}