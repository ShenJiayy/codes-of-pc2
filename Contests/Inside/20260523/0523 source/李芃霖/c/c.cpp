#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define LLM INT_MAX
const int N=1e6+50;
template<class T>
inline T read(){
	T x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+(ch-'0');
		ch=getchar(); 
	}
	return x*f;
}
template<class T>
inline void write(T x){
	if(x<0){putchar('-');write(-x);return ;}
	if(x<10){putchar(x+'0');return ;}
	write(x/10);
	putchar(x%10+'0');
	return ;
}
ll n,a[N],dp[N][10],ans=0;
int main(){
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	n=read<ll>();
	for(ll i=1;i<=n;i++) a[i]=read<ll>();
	for(ll i=0;i<=n;i++) dp[i][0]=dp[i][1]=dp[i][2]=-1;
	dp[0][0]=0; 
	for(ll i=1;i<=n;i++){
		for(ll k1=0;k1<=2;k1++){
			for(ll k2=0;k2<=2;k2++){
				if(dp[i-1][k1]==-1) continue ;
				if(k2>a[i]) continue ;
				dp[i][k2]=max(dp[i][k2],dp[i-1][k1]+(a[i]-k2+k1)/3);
			}
		}
	}
	ans=max(max(dp[n][0],dp[n][1]),dp[n][2]);
	write<ll>(ans);
	putchar('\n');
	return 0;
}
