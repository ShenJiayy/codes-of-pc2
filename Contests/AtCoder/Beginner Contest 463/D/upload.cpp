#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5;
struct Wrap {
    int l, r;
} a[N + 5];
int n;
bool check(int len) {
    
}
signed main() {
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i].l >> a[i].r;
    int l = 1, r = 1e9, ans = -1;
    while (l <= r) {
        int mid = l + r >> 1;
        if (check(mid))
            l = mid + 1, ans = mid;
        else r = mid - 1;
    } 
    cout << ans;
    return 0;
}
