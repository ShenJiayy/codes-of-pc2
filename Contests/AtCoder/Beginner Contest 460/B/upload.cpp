#include <bits/stdc++.h>
using namespace std;
#define int long long
int pow(int x) { return x * x; }
signed main() {
	int T;
    cin >> T;
    while (T --) {
        int x1, y1, x2, y2, r1, r2;
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        int d = pow(x1 - x2) + pow(y1 - y2);
        if (pow(r1 - r2) <= d && d <= pow(r1 + r2))
            puts("Yes");
        else puts("No");
    }
    return 0;
}