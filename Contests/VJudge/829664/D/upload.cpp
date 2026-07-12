#include <bits/stdc++.h>
using namespace std;
#define int long long
int C(int n, int m) {
    int res = 1;
    for (int i = 1, j = n; i <= m; i ++, j --) {
        res = res * j / i;
        if (res >= 2e9) return 2e9;
    }
    return res;
}
signed main() {
    int n;
    cin >> n;
    if (n == 1) return puts("1"), 0;
    for (int i = 16; i >= 2; i --) 
        for (int j = i * 2; ; j ++) {
            int k = C(j, i);
            if (k == n) {
                cout << j * (j + 1) / 2 + i + 1;
                return 0;
            }
            else if (k > n) break;
        }
    cout << n * (n + 1) / 2 + 2;
	return 0;
}