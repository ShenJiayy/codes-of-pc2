#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long
inline int read() { int x=0,f=1;char ch=getchar(); while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();} while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();} return x*f;}
void print(int x){if(x<0){putchar('-');x=-x;}if(x>9)print(x/10);putchar(x%10+'0');}
struct node{int t,v,id;vector < int > a;}q[100010];
int n,m,c,a[100010],mod=998244353;
void solve(int x){
	if(q[x].t==1) a[q[x].id]=(q[x].v+a[q[x].id])%mod;
	else if(q[x].t==2){for(int i=1;i<=n;++i) a[i]=(q[x].v*a[i])%mod;}
	else{for(int i=0;i<q[x].v;i++){solve(q[x].a[i]);}}
}
signed main(){
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	n=read();
	for(int i=1;i<=n;++i) a[i]=read();
	m=read();
	for(int i=1;i<=m;++i){
		q[i].t=read()%mod;
		if(q[i].t==1){q[i].id=read()%mod,q[i].v=read()%mod;}
		else if(q[i].t==2){q[i].v=read()%mod;}
		else{
			q[i].v=read()%mod;
			for(int j=1;j<=q[i].v;++j){q[i].a.push_back(read()%mod);}
		}
	}
	c=read();
	while(c--){
		int x=read()%mod;
		solve(x);
	}
	for(int i=1;i<=n;++i){
		print(a[i]%mod);
		printf(" ");
	}
	return 0;
}

