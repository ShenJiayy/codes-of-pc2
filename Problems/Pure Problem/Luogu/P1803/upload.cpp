#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6;
struct Line {
    int s, t;
} a[N + 5];
bool cmp(Line x, Line y) {
    if (x.t != y.t) return x.t < y.t;
    return x.s < y.s;
}
signed main() {
	int n;
    cin >> n;
    for (int i = 1; i <= n; i ++) 
        cin >> a[i].s >> a[i].t;
    sort(a + 1, a + n + 1, cmp);
    int end = 0, cnt = 0;
    for (int i = 1; i <= n; i ++) {
        if (a[i].s >= end)
            cnt ++, end = a[i].t;
    }
    cout << cnt;
    return 0;
}
