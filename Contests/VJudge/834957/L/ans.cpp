#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1010;
const ll mod = 998244353;
ll n, m, f[N][N], c[N][N];
bool frd[N][N];
int main() {
	cin >> n >> m;
	n *= 2ll;
	for(int i = 1, a, b; i <= m; i++) {
		cin >> a >> b;
		frd[a][b] = frd[b][a] = true;	//标记为朋友
	}
	for(int i = 1; i <= n; i++) f[i + 1][i] = 1;
	c[0][0] = 1;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= i; j++) {
			c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;	//预处理组合数
		}
	}
	for(int i = 2; i <= n; i += 2) {
		for(int l = 1, r = l + i - 1; l + i - 1 <= n; l++, r++) {
			if(frd[l][r]) f[l][r] = f[l + 1][r - 1];	//小特判
			for(int k = l + 1; k <= r - 1; k += 2) {
				if(frd[l][k]) {	//去重的关键
					f[l][r] += f[l + 1][k - 1] * f[k + 1][r] % mod * c[i / 2 + 1][(k - l + 1) / 2 + 1] % mod; //注意要乘上组合数
				}
			}
		}
	}
	cout << f[1][n];
	return 0;
}
