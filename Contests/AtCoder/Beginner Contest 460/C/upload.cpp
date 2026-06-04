#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5;
int a[N + 5], b[N + 5];
signed main() {
	int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    sort(a + 1, a + n + 1, greater<int>());
    priority_queue<int> q;
    for (int i = 1; i <= m; i ++)
        cin >> b[i], q.emplace(b[i]);
    int cnt = 0;
    for (int i = 1; i <= n; i ++) {
        while (!q.empty() && q.top() > a[i] * 2)
            q.pop();
        if (q.empty()) {
            cout << cnt;
            return 0;
        }
        cnt ++;
        q.pop();
    }
    cout << cnt;
    return 0;
}
