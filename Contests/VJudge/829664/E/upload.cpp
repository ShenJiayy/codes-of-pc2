#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 30;
int a[N + 5];
signed main() {
    #ifndef ONLINE_JUDGE
        freopen("data.in", "r", stdin);
    #endif
    int x, n = 0;
	while (cin >> x) 
        a[++ n] = x;
    int sum = 0, base = 1 << n - 1;
    for (int i = 1; i <= n; i ++)
        sum += a[i];
    sum *= base;
    cout << sum;
    return 0;
}
