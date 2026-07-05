#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 500;
char s[N + 5][N + 5], t[N + 5][N + 5], tmp[N + 5][N + 5];
const int fs[] = {0, 1, 2, 1};
signed main() {
	int n;
    cin >> n;
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= n; j ++)
            cin >> s[i][j];
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= n; j ++)
            cin >> t[i][j];
    // Opt 1.  改格子
    // Opt 2.  竖着从下往上念
    // Opt 3.  把Opt 2做3次
    // 还有，可以先转后调
    int ans = 9e18;
    for (int dx = 0; dx < 4; dx ++) {
        // 先测答案
        int res = fs[dx];
        for (int i = 1; i <= n; i ++)
            for (int j = 1; j <= n; j ++)
                if (s[i][j] != t[i][j])
                    res ++;
        ans = min(ans, res);
        for (int i = 1; i <= n; i ++)
            for (int j = 1; j <= n; j ++)
                tmp[j][n - i + 1] = s[i][j];
        memcpy(s, tmp, sizeof tmp);
    }
    cout << ans;
    return 0;
}
