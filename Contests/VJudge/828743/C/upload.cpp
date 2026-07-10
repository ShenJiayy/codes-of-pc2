#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5;
int a[N + 5];
signed main() {
    #ifndef ONLINE_JUDGE
        freopen("in.in", "r", stdin);
    #endif
    // Write here.
    int n, m, p = 0, lst = 1;
    cin >> n >> m;
    priority_queue<int> qmax;
    priority_queue<int, vector<int>, greater<int>> qmin;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    for (int i = 1; i <= m; i ++) {
        int q;
        cin >> q;
        for (int j = lst; j <= q; j ++) {
            qmax.push(a[j]);
            if (qmax.size() == i) qmin.push(qmax.top()), qmax.pop();
        }
        lst = q + 1;
        cout << qmin.top() << endl;
        qmax.push(qmin.top()), qmin.pop();
    }
    return 0;
}