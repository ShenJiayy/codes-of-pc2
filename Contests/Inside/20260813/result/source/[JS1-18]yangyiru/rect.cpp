#include <bits/stdc++.h>
using namespace std;

const int N = 505;
int n, m;
int arr[N][N], sum[N][N], sz[N][N];

int main(){
	freopen("rect.in", "r", stdin);
	freopen("rect.out", "w", stdout);
	int ans = 0;
	cin>>n>>m;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			cin>>arr[i][j];
			sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + arr[i][j];
		}
	}
	for(int a=1; a<=n; a++){
		for(int b=1; b<=m; b++){
			for(int c=a; c<=n; c++){
				for(int d=b; d<=m; d++){
					int s = sum[c][d]-sum[a-1][d]-sum[c][b-1]+sum[a-1][b-1];
					int cnt = (c-a+1) * (d-b+1);
					if(s == cnt) ans++;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
