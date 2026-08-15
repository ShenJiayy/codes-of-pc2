#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N=5e2;
int a[N+4][N+4];
bool b[N+4][N+4];
inline int read()
{
	int sum=0;
	char c=getchar();
	while(c>'9'||c<'0') c=getchar();
	while(c>='0'&&c<='9')
	{
		sum=sum*10+c-'0';
		c=getchar();
	}
	return sum;
}

int main()
{
	freopen("mask.in","r",stdin);
	freopen("mask.out","w",stdout);
	int n=read(),m=read(),q=read();
	while(q--)
	{
		int op=read(),x=read(),y=read();
		if(op==1)
		{
			int c=read();
			if(!b[x][y]) a[x][y]=c;
			if(!b[x+1][y]) a[x+1][y]=c;
			if(!b[x][y+1]) a[x][y+1]=c;
			if(!b[x+1][y+1]) a[x+1][y+1]=c;
		}
		else b[x][y]=b[x+1][y]=b[x][y+1]=b[x+1][y+1]=true;
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=n;++j) printf("%d ",a[i][j]);
		printf("\n");
	}
}
