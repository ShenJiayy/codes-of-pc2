#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5;
int a[N + 5];
signed main() {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    for (int i = 1; i <= n; i ++)
        a[i] %= k;
    for (int i = 1; i <= n; i ++) {
        
    }
    cout << *max_element(a + 1, a + n + 1) - *min_element(a + 1, a + n + 1);
    return 0;
}