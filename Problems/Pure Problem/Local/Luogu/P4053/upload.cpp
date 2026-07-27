#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1.5e5;
struct Building {
    int f, t;
} a[N + 5];
bool cmp(Building x, Building y) {
    return x.t < y.t;
}
signed main() {
	int n;
    cin >> n;
    for (int i = 1; i <= n; i ++) 
        cin >> a[i].f >> a[i].t;
    int tme = 0;
    sort(a + 1, a + n + 1, cmp);
    priority_queue<int> q;
    for (int i = 1; i <= n; i ++) {
        tme += a[i].f;
        q.push(a[i].f);
        if (tme > a[i].t)
            tme -= q.top(), q.pop();
    }
    cout << q.size();
    return 0;
}
