#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	int T;
	cin >> T;
	int n;
	cin >> n;
	int sum = 0,maxn = -1;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		sum += a[i];
		maxn = max(a[i],maxn);
	}
	if(maxn > sum - maxn) cout << 1 << '\n';
	else cout << 3 << '\n';
	T--;
	while(T--){
		int k;
		cin >> k;
		for(int i = 1;i <= k;i++){
			int x,y;
			cin >> x >> y;
			a[x] = y;
		}
		int sum = 0,maxn = -1;
		for(int i = 1;i <= n;i++){
			maxn = max(maxn,a[i]);
			sum += a[i];
		}
		if(maxn > sum - maxn) cout << 1 << '\n';
		else cout << 3 << '\n';
	}
}
