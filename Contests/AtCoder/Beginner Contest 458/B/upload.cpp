#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 100;
int a[N + 5][N + 5];
signed main() {
	int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++)
            a[i][j] = 1;
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++)
            cout << a[i][j - 1] + a[i][j + 1] + a[i - 1][j] + a[i + 1][j] << " ";
        cout << endl;
    }
    return 0;
}
