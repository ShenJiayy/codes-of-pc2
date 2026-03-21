#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 45000;
int a[N + 5];
signed main() {
    int m;
    cin >> m;
    // 构造a_i|a_j
    // i * (i - 1) / 2 = m;
    if (m == 0) {
        cout << "2\n99 37";
        return 0;
    }
    else if (m == 1) {
        cout << "2\n1 2";
        return 0;
    }
    int l = 1, r = m, n;
    while (l <= r) {
        int mid = l + r >> 1;
        // 也就是求m=n*(n-1)/2的最接近的最小值
        if (mid * (mid - 1) / 2 <= m)
            n = mid, l = mid + 1;
        else r = mid - 1;
    }
    a[1] = 1;
    for (int i = 2; i <= n; i ++)
        a[i] = a[i - 1] * 2;
    for (int i = 1; i <= n; i ++)
        cout << a[i] << " ";
    return 0;
}