#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5;
struct Choco {
    int p, d, c;
} a[N + 5];
map<int, vector<Choco>> g;
bool operator > (Choco x, Choco y) {
    if (x.p != y.p)
        return x.p > y.p;
    return x.d > y.d;
}
signed main() {
	int m, n;
    cin >> m >> n;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i].p >> a[i].d >> a[i].c;
        g[a[i].d].push_back(a[i]);
    }
    priority_queue<Choco, vector<Choco>, greater<Choco>> q;
    for (int i = 1; i <= n; i ++) 
        if (a[i].d > m)
            q.push(a[i]);
    int ans = 0;
    for (int i = m; i >= 1; i --) {
        for (Choco x : g[i])
            q.push(x);
        // if (q.empty()) continue;
        Choco t = q.top();
        q.pop();
        t.c --;
        ans += t.p;
        if (t.c)
            q.push(t);
    }  
    cout << ans;
    return 0;
}
