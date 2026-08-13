#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define LLM INT_MAX
const int N=3e5+50;
template<class T>
inline T read(){
	T x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')
		ch=getchar();
	while(ch>='0'&&ch<='9'){
		x=x*10+(ch-'0');
		ch=getchar(); 
	}
	return x;
}
template<class T>
inline void write(T x){
	if(x<10){putchar(x+'0');return ;}
	write(x/10);
	putchar(x%10+'0');
	return ;
}
int n,a[N],c,d,q,maxa,l,r,mid;
ll ans,sum,bac[N],tans,tmp1,tmp2;
int lb(ll x){
	int l=1,r=n,mid,tans=0;
	if(a[n]<x) return n+1;
	if(a[1]>=x) return 1;
	while(l<=r){
		mid=(l+r)>>1;
		if(a[mid]>=x){
			tans=mid;r=mid-1;
		}
		else l=mid+1;
	}
	return tans;
}
void binary_search(){
	l=1,r=maxa/d+1,mid;ans=0;
	while(l<=r){
		mid=(l+r)>>1;
		tmp2=lb(mid*d);
		tans=(n-tmp2+1)*d;
		tmp2--;if(tmp2!=0){
			tmp1=lb(mid*d-d);
			tans=tans+bac[tmp1]-bac[tmp2+1]-(tmp2-tmp1+1)*(mid*d-d);
		}
		if(tans>c){
			ans=mid;l=mid+1;
		}
		else r=mid-1;
	}
	return ;
}
int main(){
	freopen("d.in","r",stdin);
	freopen("d.out","w",stdout);
	n=read<int>();q=read<int>();
	for(int i=1;i<=n;i++) a[i]=read<ll>();
	sort(a+1,a+n+1);maxa=a[n];
	for(int i=n;i>=1;i--){bac[i]=bac[i+1]+a[i];}
	while(q--){
		c=read<int>();d=read<int>();
		if(d*n<=c){
			write<ll>(bac[1]);
			putchar('\n');continue ;
		}
		binary_search();
		int tmp1=lb(ans*d);
		sum=bac[tmp1]-(n-tmp1+1)*ans*d+c*ans;
		write<ll>(sum);
		putchar('\n');
	}
	return 0;
}
