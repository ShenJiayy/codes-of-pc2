#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	int n, m, cnt = 0;
    cin >> n >> m;
    while (m) {
        m = n % m;
        cnt ++;
    }
    cout << cnt;
    return 0;
}
