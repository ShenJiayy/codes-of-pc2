#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5;
int a[N + 5], sl[N + 5], sr[N + 5];
signed main() {
	int n, t;
    cin >> n >> t;
    for (int i = 1; i <= n; i ++)
        cin >> a[i], a[i] %= t;
    sort(a + 1, a + n + 1);
    int md = 0;
    for (int i = 1; i <= n; i ++)
        md = max(md, a[i + 1] - a[i]);
    md = max(md, a[1] + t - a[n]);
    int k = (t - md + 1) / 2;
    cout << k;
    return 0;
}