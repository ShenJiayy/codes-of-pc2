#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N=200;
ll x[N+4],t[N+4],a[N+4];
int n,L,ans;
bool b[N+4];
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
void dfs(int now,int sum,ll ti)
{
	int ri=9178,le=9178,ntl,ntr;
	for(int i=now+1;i<=n+now-1;++i)
	{
		if(i>n)
		{
			if(ti+L-x[i-n]+x[now]<=t[i-n]&&!b[i-n])
			{
				le=i-n;
				ntl=ti+L-x[i-n]+x[now];
				break;
			}
		}
		else
		{
			if(ti+x[i]-x[now]<=t[i]&&!b[i])
			{
				le=i;
				ntl=t[i]+x[i]-x[now];
				break;
			}
		}
	}
	for(int i=now-1;i>=now-n+1;--i)
	{
		if(i==-1&&now==0)
		{
			if(ti+x[0]+L-x[n]<=t[n]&&!b[n])
			{
				ri=n;
				ntr=ti+x[now]+L-x[n];
				break;
			}
		}
		if(i<=0&&now!=0)
		{
			if(ti+x[now]+L-x[i+n]<=t[i+n]&&!b[i+n])
			{
				ri=i+n;
				ntr=ti+x[now]+L-x[i+n];
				break;
			}
		}
		else
		{
			if(ti+x[now]-x[i]<=t[i]&&!b[i])
			{
				ri=i;
				ntr=t[i]+x[now]-x[i];
				break;
			}
		}
	}
	if(ri==le&&ri==9178)
	{
		ans=(ans<sum?sum:ans);
		return;
	}
	b[now]=true;
	if(ri==le) dfs(ri,sum+1,ntl<ntr?ntl:ntr);
	else
	{
		if(le!=9178) dfs(le,sum+1,ntl);
		if(ri!=9178) dfs(ri,sum+1,ntr);
	}
	b[now]=false;
}
int main()
{
	freopen("stamps.in","r",stdin);
	freopen("stamps.out","w",stdout);
	n=read();
	L=read();
	for(int i=1;i<=n;++i) x[i]=read();
	for(int i=1;i<=n;++i) t[i]=read();
	t[0]=-1;
	dfs(0,0,0);
	cout<<ans;
}

