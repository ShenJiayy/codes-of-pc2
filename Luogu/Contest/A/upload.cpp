#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int m;
    cin >> m;
    // 构造a_i|a_j
    // i * (i - 1) / 2 = m;
    if (m == 0) {
        cout << "2\n99 37";
        return 0;
    }
    // else if (m == 1) {
    //     cout << "2\n1 2";
    //     return 0;
    // }
    int l = 1, r = 1e5, n;
    while (l <= r) {
        int mid = l + r >> 1;
        // 也就是求m=n*(n-1)/2的最接近的最小值
        if (mid * (mid - 1) / 2 <= m)
            n = mid, l = mid + 1;
        else r = mid - 1;
    }
    int rm = m - n * (n - 1) / 2;
    cout << n + rm << endl;
    for (int i = 1; i <= 2 * rm; i ++)
        cout << 4 << " ";
    for (int i = 1; i <= n - rm; i ++)
        cout << 2 << " ";
    return 0;
}