#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5;
int a[N + 5], curr;
void dfs(int m, int stp) {
    if (m == 0) return ;
    int l = 1, r = 1e5, n;
    while (l <= r) {
        int mid = l + r >> 1;
        if (mid * (mid - 1) / 2 <= m)
            n = mid, l = mid + 1;
        else r = mid - 1;
    }
    int rm = m - n * (n - 1) / 2;
    dfs(rm, stp + 1);
    for (int i = 1; i <= n; i ++)
        a[++ curr] = stp;
}
signed main() {
    int m;
    cin >> m;
    if (m == 0) {
        cout << "2\n99 37";
        return 0;
    }
    dfs(m, 1);
    cout << curr << endl;
    for (int i = 1; i <= curr; i ++)
        cout << a[i] << " ";
    // int l = 1, r = 1e5, n;
    // while (l <= r) {
    //     int mid = l + r >> 1;
    //     if (mid * (mid - 1) / 2 <= m)
    //         n = mid, l = mid + 1;
    //     else r = mid - 1;
    // }
    // int rm = m - n * (n - 1) / 2;
    // cout << n + rm << endl;
    // for (int i = 1; i <= 2 * rm; i ++)
    //     cout << 2 << " ";
    // for (int i = 1; i <= n - rm; i ++)
    //     cout << 1 << " ";
    return 0;
}