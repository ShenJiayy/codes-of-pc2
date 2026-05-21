#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 15;

struct Status {
    int i, j, l, r, x, y;
} fr[N + 5][N * N + 5][N + 5][N + 5][2][2];
int dp[N + 5][N * N + 5][N + 5][N + 5][2][2], a[N + 5][N + 5];

int cost(int i, int l, int r) {
    return a[i][r] - a[i][l - 1];
}

void print(Status st) {
    if (st.j == 0) return ;
    print(fr[st.i][st.j][st.l][st.r][st.x][st.y]);
    for (int i = st.l; i <= st.r; i ++)
        cout << st.i << " " << i << endl;
}

signed main() {
    #ifndef ONLINE_JUDGE
        freopen("in.in", "r", stdin);
    #endif
    int n, m, k;
    cin >> n >> m >> k;
    if (k == 0) {
        cout << 0;
        return 0;
    }
    memset(dp, -0x3f, sizeof dp);
    for (int r = 0; r <= n; r ++)
        for (int i = 1; i <= m; i ++)
            for (int j = 1; j <= m; j ++)
                dp[r][0][i][j][0][0] = 0;
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++)
            cin >> a[i][j], a[i][j] += a[i][j - 1];
    Status t;
    int ans = -2e9;
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= k; j ++)
            for (int l = 1; l <= m; l ++)
                for (int r = 1; r <= m; r ++) {
                    if (j < r - l + 1) continue;
                    int len = r - l + 1;
                    for (int l1 = l; l1 <= r; l1++) {
                        for (int r1 = l1; r1 <= r; r1++) {
                            int &v = dp[i][j][l][r][0][0];
                            int val = dp[i-1][j-len][l1][r1][0][0] + cost(i, l, r);
                            if (v < val) {
                                v = val;
                                fr[i][j][l][r][0][0] = {i-1, j-len, l1, r1, 0, 0};
                            }
                        }
                    }
                    for (int l1 = l; l1 <= r; l1++) {
                        for (int r1 = r; r1 <= m; r1++) {
                            for (int y1 = 0; y1 < 2; y1++) {
                                int &v = dp[i][j][l][r][0][1];
                                int val = dp[i-1][j-len][l1][r1][0][y1] + cost(i, l, r);
                                if (v < val) {
                                    v = val;
                                    fr[i][j][l][r][0][1] = {i-1, j-len, l1, r1, 0, y1};
                                }
                            }
                        }
                    }
                    for (int l1 = 1; l1 <= l; l1++) {
                        for (int r1 = l; r1 <= r; r1++) {
                            for (int x1 = 0; x1 < 2; x1++) {
                                int &v = dp[i][j][l][r][1][0];
                                int val = dp[i-1][j-len][l1][r1][x1][0] + cost(i, l, r);
                                if (v < val) {
                                    v = val;
                                    fr[i][j][l][r][1][0] = {i-1, j-len, l1, r1, x1, 0};
                                }
                            }
                        }
                    }
                    for (int l1 = 1; l1 <= l; l1++) {
                        for (int r1 = r; r1 <= m; r1++) {
                            for (int x1 = 0; x1 < 2; x1++) {
                                for (int y1 = 0; y1 < 2; y1++) {
                                    int &v = dp[i][j][l][r][1][1];
                                    int val = dp[i-1][j-len][l1][r1][x1][y1] + cost(i, l, r);
                                    if (v < val) {
                                        v = val;
                                        fr[i][j][l][r][1][1] = {i-1, j-len, l1, r1, x1, y1};
                                    }
                                }
                            }
                        }
                    }
                    if (j == k) 
                        for (int x1 = 0; x1 < 2; x1 ++)
                            for (int y1 = 0; y1 < 2; y1 ++)
                                if (ans < dp[i][j][l][r][x1][y1]) {
                                    ans = dp[i][j][l][r][x1][y1], t = {i, j, l, r, x1, y1};
                                }
                }
    cout << "Oil : " << ans << endl; 
    print(t);
    return 0;
}