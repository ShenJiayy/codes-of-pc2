#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int m;
    cin >> m;
    // 构造a_i|a_j
    // i * (i - 1) / 2 = m;
    int l = 1, r = m, n;
    while (l <= r) {
        int mid = l + r >> 1;
        // 也就是求m=n*(n-1)/2的最接近的最小值
        if (mid * (mid - 1) / 2 <= m)
            n = mid, l = mid + 1;
        else r = mid - 1;
    }
    cout << n;
    return 0;
}