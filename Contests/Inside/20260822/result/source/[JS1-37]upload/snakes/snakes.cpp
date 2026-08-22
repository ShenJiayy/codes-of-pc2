#include <bits/stdc++.h>
using namespace std;
int a[5];
signed main() {
    freopen("snakes.in", "r", stdin);
    freopen("snakes.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T, n;
    cin >> T >> n;
    cin >> a[1] >> a[2] >> a[3];
    if (a[1] > a[2] + a[3])
        puts("1");
    while (T --) {
        int x;
        cin >> x;
        cout << ">>>>>>>>>>>>";
    }
    return 0;
}