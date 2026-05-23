#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5;
int a[N + 5], b[N + 5];
signed main() {
    freopen("b.in", "r", stdin);
    freopen("b.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    int curr = 0;
    for (int i = 1; i <= n; i ++)
        if (a[i] != a[i - 1])
            b[++ curr] = a[i];
    int p;
    if (curr == 3)
        p = 3;
    else if (curr & 1)
        p = (curr + 3) / 2;
    else 
        p = (curr + 2) / 2;
    cout << b[p];
    return 0;
}
