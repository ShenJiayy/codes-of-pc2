#include <bits/stdc++.h>
using namespace std;
#define int long long
char a[15][15];
signed main() {
	int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) for (int j = 1; j <= m; j ++) cin >> a[i][j];
    int cnt = 0;
    for (int si = 1; si <= n; si ++) for (int sj = 1; sj <= m; sj ++) 
        for (int ei = si; ei <= n; ei ++) for (int ej = sj; ej <= m; ej ++) {
            bool ok = 1;
            for (int i = si; i <= ei; i ++)
                for (int j = sj; j <= ej; j ++)
                    if (a[i][j] != a[si + ei - i][sj + ej - j]) ok = 0;
            cnt += ok;
        }
    cout << cnt;
    return 0;
}
