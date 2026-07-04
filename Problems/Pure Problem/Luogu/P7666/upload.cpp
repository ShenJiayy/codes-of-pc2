#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5;
int t[N + 5], d[N + 5];
signed main() {
	int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i ++)
        cin >> t[i], d[i - 1] = t[i] - t[i - 1] - 1, d[0] = 0;
    sort(d + 1, d + n);
    // 2 3
    int sum = n;
    for (int i = 1; i <= n - k; i ++)
        sum += d[i];
    cout << sum;
    return 0;
}