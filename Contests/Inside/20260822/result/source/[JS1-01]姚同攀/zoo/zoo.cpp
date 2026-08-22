#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
const int N=1e6+5;
int n,m,c,k,cnt;
int _1[70],ok[N];
vector<int> need[70];
int lsh[N],tot;
int rk(int x){ return lower_bound(lsh+1,lsh+1+tot,x)-lsh;}
//string ans;
ll a;
int ans[30]={1},sz=1;
int main(){
	freopen("zoo.in","r",stdin); 
	freopen("zoo.out","w",stdout);
	scanf("%d%d%d%d",&n,&m,&c,&k);
	for(int i=1;i<=n;++i){
		string s;
		cin>>s;
		for(int j=0;j<s.size();++j)
			a=a*10+s[j]-'0';
		for(int j=0;j<k;++j){
			if(a%2) _1[j]=1;
			a/=2;
		}
	}
	for(int i=1,p,q;i<=m;++i){
		scanf("%d%d",&p,&q);
		need[p].push_back(q);
		lsh[i]=q;
	}
	sort(lsh+1,lsh+1+m);
	for(int i=1;i<=m;++i)
		if(lsh[i]!=lsh[i-1]) lsh[++tot]=lsh[i];
//	for(int i=1;i<=tot;++i) printf("%d %d\n",lsh[i],rk(lsh[i]));
	for(int i=0;i<k;++i)
		for(auto j:need[i]){
			int p=rk(j);
			if(_1[i]) ok[p]=1;
		}
	for(int i=0;i<k;++i)
		for(auto j:need[i]){
			int p=rk(j);
			if(!ok[p]){
				++cnt;
				break;
			}
		}
	for(int i=1;i<=k-cnt;++i){
		int up=0;
		for(int j=0;j<=sz;++j){
			ans[j]=ans[j]*2+up;
			up=ans[j]/10;
			ans[j]%=10;
		}
		if(up) ans[++sz]=up;
	}
	for(int i=0,del=n;i<=sz&&del;++i){
		int delt=del/10+(ans[i]<del%10);
		ans[i]=(ans[i]+10-del%10)%10;
		del=delt;
	}
	while(!ans[sz]) --sz;
	for(int i=sz;i>=0;--i) printf("%d",ans[i]);
	return 0;
}

/*
18446744073709551615
*/
