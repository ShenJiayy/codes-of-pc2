#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 200;
bool a[N + 5][N + 5];
int s[N + 5];
signed main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++) {
            char c;
            cin >> c;
            a[i][j] = c - '0';
        }    
    // 先切行
    int ans = 0;
    for (int i = 1; i < n; i ++) {
        bool vis = 0;
        for (int j = 1; j <= m; j ++)
            if (a[i][j] != a[i + 1][j])
                vis = 1;
        ans += vis;
    }
    // 切完以后看列
    for (int j = 1; j < m; j ++) {
        bool vis = 0;
        for (int i = 1; i <= n; i ++)
            if (a[i][j] != a[i][j + 1])
                vis = 1;
        ans += vis;
    }
    cout << ans;
    return 0;
}
