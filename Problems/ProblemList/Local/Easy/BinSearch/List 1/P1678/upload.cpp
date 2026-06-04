#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5;
int a[N + 5], b[N + 5];
int lower(int n, int a[], int val) {
    int l = 1, r = n, ans;
    while (l <= r) {
        int mid = l + r >> 1;
        if (a[mid] <= val)
            ans = mid, l = mid + 1;
        else
            r = mid - 1;
    }
    return ans;
}
int upper(int n, int a[], int val) {
    int l = 1, r = n, ans;
    while (l <= r) {
        int mid = l + r >> 1;
        if (a[mid] >= val)
            ans = mid, r = mid - 1;
        else
            l = mid + 1;
    }
    return ans;
}
signed main() {
    int m, n;
    cin >> m >> n;
    for (int i = 1; i <= m; i ++)
        cin >> b[i];
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    sort(b + 1, b + m + 1);
    int ans = 0;
    for (int i = 1; i <= n; i ++) {
        int up = b[upper(m, b, a[i])], dn = b[lower(m, b, a[i])];
        ans += min(abs(a[i] - up), abs(a[i] - dn));
    }
    cout << ans;
    return 0;
}
