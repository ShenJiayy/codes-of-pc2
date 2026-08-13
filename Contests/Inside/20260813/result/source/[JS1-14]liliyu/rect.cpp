#include<bits/stdc++.h>
using namespace std;
int a[50][50],s[50][50];
int main(){
	freopen("rect.in","r",stdin);
	freopen("rect.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n,m;
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			cin >> a[i][j];
			s[i][j] = s[i-1][j] + s[i][j-1] + a[i][j] - s[i-1][j-1];
		}
	}
	int ans = 0;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			for(int k = i;k <= n;k++){
				for(int l = j;l <= m;l++){
					int square = (k - i + 1) * (l - j + 1);
					int sum = s[k][l] - s[i - 1][l] - s[k][j - 1] + s[i - 1][j - 1];
					if(sum == square) ans++;
				}
			}
		}
	}
	cout << ans;
}

