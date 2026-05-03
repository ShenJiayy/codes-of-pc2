#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 800;
int a[N + 5], b[N + 5];
signed main() {
    #ifndef ONLINE_JUDGE
        freopen("in.in", "r", stdin);
    #endif
    int n, m, k;
    cin >> n >> m >> k;
    priority_queue<int> q;
    q.push(0);
    while (n --) {
        for (int i = 1; i <= m; i ++)
            cin >> a[i];
        sort(a + 1, a + m + 1);
        int curr = 0;
        for (; !q.empty(); q.pop()) b[++ curr] = q.top();
        for (int i = 1; i <= m; i ++)
            for (int j = curr; j >= 1; j --) {
                if (q.size() < k) q.push(a[i] + b[j]);
                else if (q.top() > a[i] + b[j])
                    q.pop(), q.push(a[i] + b[j]);
                else
                    break;
            }
    }
    int curr = 0;
    for (; !q.empty(); q.pop()) b[++ curr] = q.top();
    for (int i = k; i >= 1; i --)
        cout << b[i] << " ";
    return 0;
}