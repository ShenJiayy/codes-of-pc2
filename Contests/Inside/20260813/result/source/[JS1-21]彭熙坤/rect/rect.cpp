#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=250005;
int n,m;
int a[MAXN],ans;
vector <int> s[MAXN];
map<int,int> p;
signed main(){
	freopen("rect.in","r",stdin);
	freopen("rect.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	if(n==1){
		p[0]++;
		for(int i=1;i<=m;i++){
			scanf("%lld",&a[i]);
			a[i]--;
			a[i]+=a[i-1];
			ans+=p[a[i]];
			p[a[i]]++;
		}
		printf("%lld",ans);
		return 0;
	}
	for(int j=1;j<=m;j++) s[0].push_back(0);
	for(int i=1;i<=n;i++){
		s[i].push_back(0);
		for(int j=1;j<=m;j++){
			int x;
			scanf("%lld",&x);
			x--;
			s[i].push_back(x);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			s[i][j]+=s[i-1][j]+s[i][j-1]-s[i-1][j-1];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			for(int k=1;k<=i;k++){
				for(int h=1;h<=j;h++){
					if(s[i][j]-s[i][h-1]-s[k-1][j]+s[k-1][h-1]==0) ans++;
				}
			}
		}
	}
	printf("%lld",ans);
	return 0;
}
