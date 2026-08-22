#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int m,c,k;
unsigned long long n;
unsigned long long ans=0;
unsigned long long qwq;
int vis[N];
unsigned long long qpow(unsigned long long a,unsigned long long b){
	if(b==0)return 1;
	if(b==1)return a;
	long long t=qpow(a,b/2);
	if(b%2)return t*t*a;
	else return t*t;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	cin>>n>>m>>c>>k;
	for(int i=1ull;i<=n;i++){
		int x;
		cin>>x;
		ans|=x;
	}
	qwq=k;
//	cout<<ans<<" "<<(1<<2)<<"\n";
	for(int i=1;i<=m;i++){
		int p,q;
		cin>>p>>q;
	//	cout<<ans<<" "<<(1<<p)<<" "<<p<<((1<<p)&ans)<<"\n";
		if(((1<<p)&ans)==0){
		//	cout<<vis[p]<<" "<<p;
			if(!vis[p])vis[p]=1,qwq--;
		}
	}
//	cout<<qwq;
	cout<<qpow(2ull,qwq)-n;
	return 0;
}
