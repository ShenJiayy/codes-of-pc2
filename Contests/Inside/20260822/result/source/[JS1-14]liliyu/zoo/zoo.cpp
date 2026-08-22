#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
ull animal;
bool food[100];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	ull n,m,c,k;
	cin >> n >> m >> c >> k;
	for(int i = 0;i <= 90;i++){
		food[i] = true;
	}
	if(m == 0 && n == 0 && k == 64){
		cout << "18446744073709551616";
		return 0;
	}
	for(ull i = 1;i <= n;i++){
		ull x;
		cin >> x;
		animal |= x;
	}
//	cout << animal << '\n';
	for(ull i = 1;i <= m;i++){
		ull p,q;
		cin >> p >> q;
		if(((animal >> p) & 1) == 0) food[p] = false;
	}
//	for(int i = 0;i < k;i++){
//		cout << food[i];
//	}
//	cout << '\n';
//	cout << animal << " " << k << "\n";
	ull ans = 1;
	for(ull i = 0;i < k;i++){
		if(food[i]) ans *= 2ull;
	}
	cout << ans - n;
}
