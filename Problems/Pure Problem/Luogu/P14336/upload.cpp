#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	int n;
    cin >> n;
    int sum = 0;
    while (n --) {
        int a, b;
        cin >> a >> b;
        sum = max(sum, max(a + b, 2 * a));
    }
    cout << sum;
    return 0;
}