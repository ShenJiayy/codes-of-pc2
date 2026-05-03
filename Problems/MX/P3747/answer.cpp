#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=50005;
struct seg{
	int v,mn;
}t[maxn<<2];
int n,m,p,c;
int len=0;
int phi[30];
long long s1[10005][30],s2[10005][30];
bool b1[maxn][30],b2[maxn][30];
long long f[maxn][30][30];
bool bj[maxn][30][30];
int g[30];
int a[maxn];
int read(){
	int x=0,y=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return x*y;
}
int gcd(register int x,register int y){
	return y==0?x:gcd(y,x%y);
}
int get_phi(int x){
	long long ans=x;
	for(long long i=2;i<=sqrt(x);i++){
		if(x%i)continue;
		ans=ans*(i-1)/i;
		while(x%i==0)x/=i;
	}
	if(x>1)ans=ans*(x-1)/x;
	return ans;
}
void pre(){
	int x=p;
	phi[0]=p;
	while(x!=1){x=get_phi(x);phi[++len]=x;}
	phi[++len]=1;
	for(int i=0;i<=len;i++)g[i]=gcd(c,phi[i]);
	for(int j=0;j<=len;j++){
		s2[0][j]=1;
		for(int i=1;i<=10000;i++){
			s2[i][j]=s2[i-1][j]*c;
			if(s2[i][j]>=phi[j]){s2[i][j]%=phi[j];b2[i][j]=1;}
			b2[i][j]|=b2[i-1][j];
		}
	}
	for(int j=0;j<=len;j++){
		s1[0][j]=1;
		b1[1][j]=b2[10000][j];
		for(int i=1;i<=10000;i++){
			s1[i][j]=s1[i-1][j]*s2[10000][j];
			if(s1[i][j]>=phi[j]){s1[i][j]%=phi[j];b1[i][j]=1;}
			b1[i][j]|=b1[i-1][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int k=0;k<=len;k++){
			f[i][0][k]=a[i]%phi[k];
			if(a[i]>=phi[k])bj[i][0][k]=1;
		}
		for(int j=1;j<=len;j++){
			f[i][j][len]=0;
			for(int k=0;k<len;k++){
				f[i][j][k]=s1[f[i][j-1][k+1]/10000][k]*s2[f[i][j-1][k+1]%10000][k];
				bj[i][j][k]=(b1[f[i][j-1][k+1]/10000][k]||b2[f[i][j-1][k+1]%10000][k]);
				if(f[i][j][k]>=phi[k]){f[i][j][k]%=phi[k];bj[i][j][k]=1;}
				if(g[k]!=1&&bj[i][j-1][k+1]){
					f[i][j][k]=f[i][j][k]*s1[phi[k+1]/10000][k]%phi[k]*s2[phi[k+1]%10000][k];
					if(f[i][j][k]>=phi[k]){f[i][j][k]%=phi[k];bj[i][j][k]=1;}
					bj[i][j][k]=(bj[i][j][k]||b1[phi[k+1]/10000][k]||b2[phi[k+1]%10000][k]);
				}
			}	
		}
	}
	return ;
}
void pushup(int k){
	t[k].v=t[k<<1].v+t[k<<1|1].v;
	t[k].mn=min(t[k<<1].mn,t[k<<1|1].mn);
	return ;
}
void build(int k,int l,int r){
	if(l==r){
		t[k].v=a[l];
		t[k].mn=0;
		return ;
	}
	int mid=l+((r-l)>>1);
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
	pushup(k);
	return ;
}
void modify(int k,int l,int r,int x,int y){
	if(t[k].mn>=len)return ;
	if(l>y||r<x)return ;
	if(l==r){
		t[k].mn++;t[k].v=f[l][t[k].mn][0]%p;
		return ;
	}
	int mid=l+((r-l)>>1);
	if(t[k<<1].mn<len)modify(k<<1,l,mid,x,y);
	if(t[k<<1|1].mn<len)modify(k<<1|1,mid+1,r,x,y);
	pushup(k);
	return ;
}
int query(int k,int l,int r,int x,int y){
	if(l>y||r<x)return 0;
	if(l>=x&&r<=y)return t[k].v%p;
	int mid=l+((r-l)>>1);
	return (query(k<<1,l,mid,x,y)+query(k<<1|1,mid+1,r,x,y))%p;
}
signed main(){
	n=read();m=read();p=read();c=read();
	for(int i=1;i<=n;i++)a[i]=read();
	pre();
	build(1,1,n);
	for(int i=1;i<=m;i++){
		int opt,l,r;
		opt=read();l=read();r=read();
		if(opt==0)modify(1,1,n,l,r);
		else printf("%lld\n",query(1,1,n,l,r));
	}
	return 0;
}

