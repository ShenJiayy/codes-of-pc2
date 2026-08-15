#include <bits/stdc++.h>

#define ed end()
#define bg begin()
#define mp make_pair
#define pb push_back
#define all(x) x.bg,x.ed
#define newline puts("")
#define si(x) ((int)x.size())

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int Maxn = 1e5+10;
const int Inf = 0x7f7f7f7f;
const ll Inf_ll = 1ll*Inf*Inf;
const int Mod = 1e9+7;
const double eps = 1e-7;

using namespace std;
ll a[505][505];
bool f[505][505];

signed main(){
    freopen("mask.in","r",stdin);
    freopen("mask.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	int n, m, q;
	cin>>n>>m>>q;
	for(int i=1;i<=q;i++){
		int op, x, y;
		cin>>op>>x>>y;
		if( op == 1 ){
			int c;
			cin>>c;
			if( f[x][y] != 1 )      a[x][y]=c;
			if( f[x+1][y] != 1 )    a[x+1][y]=c;
			if( f[x][y+1] != 1 )    a[x][y+1]=c;
			if( f[x+1][y+1] != 1 )  a[x+1][y+1]=c;
		}
		else  f[x][y] = f[x+1][y] = f[x][y+1] = f[x+1][y+1] = 1;
	}
	for(int i=1;i<=n;i++,cout<<endl){
		for(int j=1;j<=m;j++){
			cout<<a[i][j]<<' ';
		}
	}
	return 0;
}
