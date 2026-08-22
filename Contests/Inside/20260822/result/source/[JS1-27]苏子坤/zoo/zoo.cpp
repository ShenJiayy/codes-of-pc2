#include<bits/stdc++.h>
#define int unsigned long long
using namespace std;
bool can[1000005],have[70];
int n,m,c,k;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
void init(int x){
	for(int i=0;i<k;i++){
		if(((x>>i)&1))have[i]=1;
	}
}
int qpow(int a,int b){
	int ret=1;
	while(b){
		if(b&1){
			ret*=a;
		}
		a*=a;
		b>>=1;
	}
	return ret;
}
signed main(){
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	n=read(),m=read(),c=read(),k=read();
	for(int i=1;i<=n;i++){
		int t=read();
		init(t);
	}
	int cnt=0;
	for(int i=1;i<=m;i++){
		int p=read(),q=read();
		if(!have[p]){
			cnt++;
			have[p]=1;
		}
	}
	cout<<qpow(2,k-cnt)-n;
	return 0;
}
