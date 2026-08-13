#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N=3e5;
int s[10][N+4];
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
	freopen("gitara.in","r",stdin);
	freopen("gitara.out","w",stdout);
	int n=read(),p=read();
	ll ans=0;
 	for(int i=1;i<=n;++i)
	{
		int x=read(),y=read();
		while(s[x][0]!=0&&s[x][s[x][0]]>y)
		{
			--s[x][0];
			++ans;
		}
		if(s[x][s[x][0]]!=y)
		{
			s[x][++s[x][0]]=y;
			++ans;
		}
	}
	cout<<ans;
}
