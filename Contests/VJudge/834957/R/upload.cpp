#include <bits/stdc++.h>
using namespace std;
#define int long long
/*
dp[i][j][k][0/1/2]表示第i行第j列一共粉刷了k次，0/1/2分别表示当前格子没有涂色/涂了错的颜色/涂了对的颜色， 然后我们考虑逐格转移：
当j=1也就是出于每行的第一个位置时，我们要考虑上一行的最后一个位置。

即
dp[i][j][k][0]=max(dp[i-1][m][k][1],dp[i-1][m][k][2],dp[i-1][m][k][0]);
dp[i][j][k][1]=max(dp[i-1][m][k-1][2],dp[i-1][m][k-1][1],dp[i-1][m][k-1][0]);
dp[i][j][k][2]=max(dp[i-1][m][k-1][2],dp[i-1][m][k-1][1],dp[i-1][m][k-1][0])+1;

其余位置要考虑这个格子颜色是否和前一个格子的颜色相等。

如果相等，就有
dp[i][j][k][2]=dp[i][j-1][k][2]+1; // 可以直接接上
dp[i][j][k][1]=max(dp[i][j-1][k][1],dp[i][j-1][k-1][0]); // 前面涂错或不涂
dp[i][j][k][0]=max(dp[i][j-1][k][0],dp[i][j-1][k][1]); // 前面涂错或不涂 

如果不相等,
dp[i][j][k][2]=max(dp[i][j-1][k-1][2],max(dp[i][j-1][k][1],dp[i][j-1][k-1][0]))+1; // 前面可能有三种情况
dp[i][j][k][1]=max(dp[i][j-1][k][2],dp[i][j-1][k-1][0]); // 涂对或不涂       
dp[i][j][k][0]=max(dp[i][j-1][k][0],dp[i][j-1][k][2]); // 涂对或不涂

可以用滚动数组压掉第一维，这样空间复杂度是O(nT),时间复杂度是O(nmT)，还是可以过的
*/
const int N = 50, T = 2500;
int dp[2][N + 5][T + 5][3];
char c[N + 5][N + 5];
int max(int a, int b, int c) {
	return max(a, max(b, c));
}
signed main() {
	int n, m, t;
	cin >> n >> m >> t;
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= m; j ++)
			cin >> c[i][j];
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= m; j ++)
			for (int k = 1; k <= t; k ++) {
				if (j == 1) {
					dp[i & 1][j][k][0] = max(dp[i - 1 & 1][m][k][0], dp[i - 1 & 1][m][k][1], dp[i - 1 & 1][m][k][2]);
					dp[i & 1][j][k][1] = max(dp[i - 1 & 1][m][k - 1][0], dp[i - 1 & 1][m][k - 1][1], dp[i - 1 & 1][m][k - 1][2]);
					dp[i & 1][j][k][2] = max(dp[i - 1 & 1][m][k - 1][0], dp[i - 1 & 1][m][k - 1][1], dp[i - 1 & 1][m][k - 1][2]) + 1;
				}
				else if (c[i][j] == c[i][j - 1]) {
					dp[i & 1][j][k][0] = max(dp[i & 1][j - 1][k][0], dp[i & 1][j - 1][k][1]);
					dp[i & 1][j][k][1] = max(dp[i & 1][j - 1][k - 1][0], dp[i & 1][j - 1][k][1]);
					dp[i & 1][j][k][2] = dp[i & 1][j - 1][k][2] + 1;
				}
				else {
					dp[i & 1][j][k][0] = max(dp[i & 1][j - 1][k][0], dp[i & 1][j - 1][k][2]);
					dp[i & 1][j][k][1] = max(dp[i & 1][j - 1][k - 1][0], dp[i & 1][j - 1][k][2]);
					dp[i & 1][j][k][2] = max(dp[i & 1][j - 1][k - 1][0], dp[i & 1][j - 1][k][1], dp[i & 1][j - 1][k - 1][2]) + 1;
				}
			}
	cout << max(dp[n & 1][m][t][0], dp[n & 1][m][t][1], dp[n & 1][m][t][2]);
	return 0;
}
