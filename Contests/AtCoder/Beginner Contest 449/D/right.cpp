#include <bits/stdc++.h>
using namespace std;
#define int long long
int max(int i, int j, int k, int l) {
    return max(max(i, j), max(k, l));
}
signed main() {
    int l, r, u, d;
    cin >> l >> r >> d >> u;
    // (l, u) (l, d) (r, d) (r, u)
    int cnt = 0;
    for (int i = l; i <= r; i ++)
        for (int j = d; j <= u; j ++)
            if (max(abs(i), abs(j)) % 2 == 0)
                cnt ++;
    cout << cnt;
    return 0;
}