#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 500;
int a[N + 5][N + 5], s[N + 5][N + 5];
signed main() {
	int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++) {
            char c;
            cin >> c;
            a[i][j] = c - '0';
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];
        }
    int cnt = 0;
    for (int r1 = 1; r1 <= n; r1 ++)
        for (int r2 = r1; r2 <= n; r2 ++)
            for (int c1 = 1; c1 <= m; c1 ++)
                for (int c2 = c1; c2 <= m; c2 ++) 
                    cnt += s[r2][c2] - s[r1 - 1][c2] - s[r2][c1 - 1] + s[r1 - 1][c1 - 1] == k;
    cout << cnt;
    return 0;
}
