#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long
int cf(int base,int p){
	if(p==0) return 1;
	int ans=1,tmp=base;
	while(p!=0) {
		if(p&1) {
			ans=ans*tmp;
		}
		tmp=tmp*tmp;
		p=p>>1;
	}
	ans=ans;
	return ans;
}
inline int read() { int x=0,f=1;char ch=getchar(); while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();} while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();} return x*f;}
void print(int x){if(x<0){putchar('-');x=-x;}if(x>9)print(x/10);putchar(x%10+'0');}
int n,a,pq,p,q,x,m,c,k,cnt,val[70];
signed main(){
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	n=read(),m=read(),c=read(),k=read();
	for(int i=1;i<=n;++i){
		x=read();
		a|=x;
	}
	for(int i=1;i<=m;++i){
		p=read(),q=read();
		if((a|cf(2,p))!=a&&!val[p]) val[p]=1,cnt++;
	}
	print(max(0llu,cf(2,k-cnt)-n));
	return 0;
}

