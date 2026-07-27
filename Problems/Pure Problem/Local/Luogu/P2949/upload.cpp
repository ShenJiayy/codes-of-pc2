#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5;
struct Work {
    int d, p;
} a[N + 5];
bool cmp(Work x, Work y) {
    return x.d < y.d;
}
signed main() {
	int n;
    cin >> n;
    for (int i = 1; i <= n; i ++) 
        cin >> a[i].d >> a[i].p;
    sort(a + 1, a + n + 1, cmp);
    priority_queue<int, vector<int>, greater<int>> q;
    int ans = 0;
    for (int i = 1; i <= n; i ++) {
        ans += a[i].p;
        q.push(a[i].p);
        if (q.size() > a[i].d)
            ans -= q.top(), q.pop();  
    }
    cout << ans;
    return 0;
}
