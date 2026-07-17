#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5;
struct Plc {
    int p, t;
} a[N + 5];
bool cmp(Plc x, Plc y) {
    return x.p < y.p;
}
signed main() {
	int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
        cin >> a[i].p >> a[i].t;
    sort(a + 1, a + n + 1, cmp);
    int ans = 0, tme = 0, cnt = 0;
    priority_queue<int> q;
    for (int i = 1; i <= n; i ++) {
        tme += a[i].p - a[i - 1].p;
        q.push(a[i].t);

        cnt ++;
        tme += a[i].t;

        while (!q.empty() && tme > m) {
            int t = q.top();
            q.pop();
            tme -= t;
            cnt --;
        }
        if (tme > m) break;
        
        ans = max(ans, cnt);
    }
    cout << ans;
    return 0;
}
