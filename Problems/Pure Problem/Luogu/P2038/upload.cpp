#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[256][256];
signed main() {
	int d, n;
    cin >> d >> n;
    for (int i = 1; i <= n; i ++) {
        int x, y, k;
        cin >> x >> y >> k;
        a[x][y] = k;
    }
    int ans = 0, ansc;
    for (int i = 0; i <= 128; i ++)
        for (int j = 0; j <= 128; j ++) {
            int cnt = 0,
                ll = max(i - d, 0ll), 
                rr = min(i + d, 128ll),
                uu = max(j - d, 0ll),
                dd = min(j + d, 128ll);
            for (int ii = ll; ii <= rr; ii ++)
                for (int jj = uu; jj <= dd; jj ++)
                    cnt += a[ii][jj];
            if (ans < cnt)
                ans = cnt, ansc = 1;
            else if (ans == cnt)
                ansc ++;
        }
    cout << ansc << " " << ans;
    return 0;
}