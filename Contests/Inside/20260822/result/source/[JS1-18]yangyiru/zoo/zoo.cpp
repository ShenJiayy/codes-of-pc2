#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e6 + 5;
int n, m, c, k;
int p[N], food[N];
bool vis[65];
ll a[N];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("zoo.in", "r", stdin);
	freopen("zoo.out", "w", stdout);
	cin>>n>>m>>c>>k;
	ll tier = 0;
	for(int i=1; i<=n; i++){
		cin>>a[i];
		tier |= a[i]; //记录每一位 
	}
	for(int i=1; i<=m; i++){
		cin>>p[i]>>food[i];
	}
	int cnt = 0;
	for(int i=1; i<=m; i++){
		if(!(tier & (1 << p[i]))){ //如果该规则存在且该饲料未购买 
			vis[p[i]] = 1;
		}
	}
	for(int i=0; i<k; i++){
		if(vis[i]) cnt++;
	}
	ll ans = (1<<(k-cnt)) - n;
	cout<<ans;
	return 0;
}
