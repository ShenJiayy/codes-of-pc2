#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
int n, T;
int a[N], b[N];

void solve(){
	int cnt = n;
	for(int i=1; i<=n; i++) b[i] = a[i];
	for(int i=n; i>1; i--){
		bool flag = 1;
		for(int j=1; j<=i-1; j++){
			if(b[i] >= b[j]){
				if(j == i-1){
					cnt--;
					flag = 0;
					break;
				}
				if(b[i]-b[j] < b[j+1]){
					flag = 0;
					break;
				}
				else{
					b[i] -= b[j];
					b[j] = -1;
					cnt--;
				}
			}
		}
		if(!flag) break;
	}
	cout<<cnt<<'\n';
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("snakes.in", "r", stdin);
	freopen("snakes.out", "w", stdout);
	cin>>T>>n;
	for(int i=1; i<=n; i++){
		cin>>a[i];
	}
	solve();
	T--;
	while(T--){
		int k;
		cin>>k;
		for(int i=1; i<=k; i++){
			int x, y;
			cin>>x>>y;
			a[x] = y;
		}
		solve();
	}
	return 0;
}
