#include<bits/stdc++.h>
using namespace std;
#define int __int128
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
void out(int x){
    if(x<0)putchar('-'),x=-x;
    if(x<10)putchar(x+'0');
    else out(x/10),putchar(x%10+'0');
}
int qpow(int a,int b){
	int res=0;
	while(b){
		if(b&1)res=res*a;
		a*=a;
		b>>=1;
	}
	return res;
}
int t,x,y,a[1000005],vis[1000005],g,cnt;
signed main(){
	//freopen("zoo.in","r",stdin);
	//freopen("zoo.out","w",stdout);
	int n=read(),m=read(),c=read(),k=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=m;i++){
		int p=read(),q=read();
		t|=(1<<p);
		if(!vis[p])y++;
		vis[p]=1;
	}
	for(int i=1;i<=n;i++)a[i]&=t;
	for(int i=0;i<=n;i++)x|=a[i];
	for(int i=0;i<k;i++)if(x&(1<<i))cnt++;
	out((1<<(k-g+cnt))-n);
	return 0;
}
