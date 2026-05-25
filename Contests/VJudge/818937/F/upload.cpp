#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[200], b[200];
int solve(int n) {
    for (int i = 1; i <= n; i ++)
        for (int j = i + 1; j <= n; j ++)   
            if ((b[j] - b[i]) % __gcd(a[i], a[j]))
                return puts("impossible"), 0;
    return puts("possible"), 0;
}
signed main() {
    int T;
    cin >> T;
    while (T --) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i ++)
            cin >> a[i] >> b[i], b[i] = a[i] - b[i];
        solve(n);
    }
    return 0;
}