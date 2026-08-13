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
ll n,a[N];
ll ansc=LLM,ansf=-1,last[N];
int main(){
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	n=read<ll>();
	for(ll i=1;i<=n;i++) a[i]=read<ll>();
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;i++){
		if(i!=1&&a[i]==a[i-1]) continue ;
		ll tmp=n-i+1-i+1;tmp=(tmp<0?-tmp:tmp);
		if(tmp<=ansc){
			ansc=tmp;ansf=a[i];
		}
	}
	write<ll>(ansf);
	putchar('\n');
	return 0;
}
