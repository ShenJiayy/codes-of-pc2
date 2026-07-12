#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1000;
int a[N + 5][N + 5];
signed main() {
	int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++)
            cin >> a[i][j];
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++)
            for (int k = 1; 1 <= i - k && i + k <= n && 1 <= j - k && j - k <= m; k ++) {
                
            }
    return 0;
}
