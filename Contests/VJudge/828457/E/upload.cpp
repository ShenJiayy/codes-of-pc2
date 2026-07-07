#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 2e4, NN = 4e4, L = 40, INF = 1e8;
int dp[20010][45][45], a[NN + 5], b[NN + 5], c[NN + 5], n, l[N + 5], r[N + 5];

int dfs(int id, int x, int y) {
    if (id >= n) 
        return c[id] * (a[id] + x) * (b[id] + y);
    if (dp[id][x][y] != dp[0][0][0])
        return dp[id][x][y];
    int ans1 = dfs(l[id], x + 1, y) + dfs(r[id], x, y);
    int ans2 = dfs(l[id], x, y) + dfs(r[id], x, y + 1);
    dp[id][x][y] = min(ans1, ans2);
    return dp[id][x][y];
}

signed main() {
    #ifndef ONLINE_JUDGE
        freopen("2/in.in", "r", stdin);
    #endif
    memset(dp, 0x3f, sizeof dp);
    cin >> n;
    for (int i = 1; i < n; i ++) {
        int ss, tt;
        cin >> ss >> tt;
        if (ss < 0) ss = n - ss - 1;
        if (tt < 0) tt = n - tt - 1;
        l[i] = ss, r[i] = tt;
    }
    for (int i = n; i <= 2 * n - 1; i ++)
        cin >> a[i] >> b[i] >> c[i];
    cout << dfs(1, 0, 0);
    return 0;
}

/*
那个式子是唬你的
直接考虑倒推
设f[u][i][j]表示从根到u有i条没标记的L边和j条没标记的R边
对于每个叶子节点枚举有多少没有被标记的L边(i)和R边(j)
f[u][i][j]=c_u(a_u+i)(b_u+j)
对于非叶子节点枚举删哪条边
f[u][i][j]=min(f[lson][i+1][j]+f[rson][i][j],f[lson][i][j]+f[rson][i][j+1])
Ans=f[1][0][0]
貌似这题还可以卡空间
*/