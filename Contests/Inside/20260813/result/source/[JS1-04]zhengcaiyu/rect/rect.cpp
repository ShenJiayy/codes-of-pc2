#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N=30,M=25e4;
int a[N+4][N+4],b[N+4][N+4],kk[M+4],jj[M+4];
inline int read()
{
	int sum=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0')
	{
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		sum=sum*10+c-'0';
		c=getchar();
	}
	return sum*f;
}

int main()
{
	freopen("rect.in","r",stdin);
	freopen("rect.out","w",stdout);
	int n=read(),m=read();
	ll ans=0;
	if(n<=30&&m<=30)
	{
		for(int i=1;i<=n;++i) for(int j=1;j<=m;++j) a[i][j]=read();
		for(int i=1;i<=n;++i) for(int j=1;j<=m;++j) b[i][j]=b[i][j-1]+b[i-1][j]-b[i-1][j-1]+a[i][j];
		for(int i=1;i<=n;++i) for(int j=1;j<=m;++j) for(int k=i;k<=n;++k) for(int l=j;l<=m;++l) if(b[k][l]-b[k][j-1]-b[i-1][l]+b[i-1][j-1]==(k-i+1)*(l-j+1)) ++ans;
		cout<<ans;
		return 0;
	}
	if(n==1)
	{
		for(int i=1;i<=m;++i) kk[i]=read();
		for(int i=1;i<=m;++i) jj[i]=jj[i-1]+kk[i];
		for(int i=1;i<=m;++i) for(int j=i;j<=m;++j) if(jj[j]-jj[i-1]==j-i+1) ++ans;
		cout<<ans;
	}
}
