#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2000;
int a[N + 5][N + 5], ans[N + 5][N + 5];
void init(int n, int m, int k) {
    a[0][1] = 1;
    for (int i = 1; i <= n; i ++) {
        a[i][0] = 1;
        for (int j = 1; j <= min(i, m); j ++)
            a[i][j] = a[i - 1][j] + a[i - 1][j - 1], 
            a[i][j] %= k,
            ans[i][j] = ans[i - 1][j] + ans[i][j - 1] -
                        ans[i - 1][j - 1] + !a[i][j];
        ans[i][i + 1] = ans[i][i];
    }
}

signed main() {
	int T, k;
    cin >> T >> k;
    init(N, N, k);
    while (T --) {
        int n, m;
        cin >> n >> m;
        cout << ans[n][min(n, m)] << endl;
    }
    return 0;
}