#include<bits/stdc++.h>
#define ll int
using namespace std;
#define LLM INT_MAX
#define set_it set<int>::iterator
const int N=3550;
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
ll n,a[N],ans=0,st[N][5][20],t,logs[N],cnt=0;
map<ll,ll> mp;bool flag=1;
void init_logs(){
	logs[1]=0;
	for(ll i=2;i<N;i++) logs[i]=logs[i/2]+1;
	return ;
}
void init_st(){
	for(ll c=0;c<=3;c++){
		for(ll k=1;k<=logs[n];k++){
			for(ll i=1;i<=n;i++){
				if(i+(1<<(k-1))>n) continue ;
				st[i][c][k]=min(st[i][c][k-1],st[i+(1<<(k-1))][c][k-1]);
			}
		}
	}
	return ;
}
ll ask(ll l,ll r,ll c){
	if(l>r) return LLM;
	ll k=logs[r-l+1];
	cnt+=2;
	return min(st[l][c][k],st[r-(1<<k)+1][c][k]);
}
ll calc(ll k1,ll k2,ll k3){
	ll ret=a[k3]-a[k2];
	ret=min(ret,ask(1,k1-t-1,0));
	ret=min(ret,ask(max(1,k1-t),min(k1-1,k2-t-2),1));
	ret=min(ret,ask(max(1,k2-t-1),min(k1-1,k3-t-3),2));
	ret=min(ret,ask(max(1,k3-t-2),min(k1-1,n-t-3),3));
	ret=min(ret,ask(k1+1,k2-t-1,0));
	ret=min(ret,ask(max(k1+1,k2-t),min(k2-1,k3-t-2),1));
	ret=min(ret,ask(max(k1+1,k3-t-1),min(k2-1,n-t-2),2));
	ret=min(ret,ask(k2+1,k3-t-1,0));
	ret=min(ret,ask(max(k2+1,k3-t),min(k3-1,n-t-1),1));
	ret=min(ret,ask(k3+1,n-t,0));
	return ret;
}
void print(){
	for(ll c=0;c<=3;c++){
		for(ll i=1;i<=n;i++){
			for(ll k=0;k<=logs[n];k++){
				cout<<st[i][c][k]<<" ";
			}
			cout<<endl;
		}
		cout<<endl<<endl;
	}
	return ;
}

int main(){
	freopen("f.in","r",stdin);
	freopen("f.out","w",stdout);
	init_logs();
	n=read<ll>();
	for(ll i=1;i<=n;i++){
		a[i]=read<ll>();
		if(a[i]!=i) flag=0;
	}
	if(flag){
		if(n%2==0) write<ll>(n/2);
		else write<ll>((n-1)/2);
		putchar('\n');
		return 0;
	}
	if(n%2==0){
		ans=LLM;
		for(ll i=1;i<=n/2;i++) ans=min(ans,a[i+n/2]-a[i]);
		write<ll>(ans);
		putchar('\n');
		return 0;
	}
	t=(n-3)/2;
	if(n==3){
		if(a[2]-a[1]==a[3]-a[2])
			write<ll>(a[3]-a[2]);
		else{putchar('-');putchar('1');}
		putchar('\n');
		return 0;
	}
	for(ll i=1;i<=n-t;i++){
		for(ll j=0;j<=3;j++){
			if(i+t+j>n) st[i][j][0]=LLM;
			else st[i][j][0]=a[i+j+t]-a[i];
		}
	}
	init_st();
	ans=-1;
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=i-1;j++){
			if(mp.find(2*a[j]-a[i])!=mp.end()){
				ans=max(ans,calc(mp[2*a[j]-a[i]],j,i));
			}
		}
		mp[a[i]]=i;
	}
	if(ans==-1){
		putchar('-');
		putchar('1');
		return 0;
	}
	write<ll>(ans);
	putchar('\n');
	return 0;
}
