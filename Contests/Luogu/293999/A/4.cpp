#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 1; i < n; i ++)
        ans += i * (n - i);
    cout << ans * 2;
    return 0;
}