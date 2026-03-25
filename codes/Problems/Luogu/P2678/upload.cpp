#include <bits/stdc++.h>
using namespace std;
// #define int long long
const int N = 50000;
int a[N + 10], n, m;
bool check(int l) {
    int p = 0, mv = 0;
    for (int i = 0; i < n + 1; ) {
        i ++;
        if (a[i] - a[p] < l) mv ++;
        else p = i;
    }
    return mv <= m;
}
signed main() {
	int le;
    cin >> le >> n >> m;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    a[n + 1] = le;
    int l = 1, r = le, ans;
    while (l <= r) {
        int mid = l + r >> 1;
        if (check(mid)) ans = l, l = mid + 1;
        else r = mid - 1;
    }
    cout << ans;
    return 0;
}