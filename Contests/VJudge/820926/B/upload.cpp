#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	int n, k;
    cin >> n >> k;
    double ans = 0;
    for (int i = 1; i <= n; i ++) {
        int bi = i;
        double px = 1;
        while (bi < k)
            px /= 2, bi *= 2;
        ans += px / n;
    }
    printf("%.10lf", ans);
    return 0;
}
