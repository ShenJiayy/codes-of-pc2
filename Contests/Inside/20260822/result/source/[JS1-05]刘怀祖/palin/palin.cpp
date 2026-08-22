#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int T,n,nn,a[N<<1],av[N<<1],bk[N],cnt,l,r,id[N][3],tp[N];
char ans[N<<1];
int sm(int x)
{
	if(id[a[x]][0]==x)return id[a[x]][1];
	return id[a[x]][0];
}
int chk(int x,int y)
{
	if(av[x]==1)return x;
	if(av[y]==1)return y;
	return -1;
}
int run(int x)
{
	l=1;r=nn;cnt=0;
	for(int i=1;i<=n;i++)
		bk[i]=0;
	for(int i=1;i<=nn+1;i++)
		av[i]=ans[i]=0;
	for(int i=1;i<=n;i++)
	{
		int did;
		if(i==1)did=x;
		else
		{
			did=chk(l,r);
			if(did==-1)break;
		}
		if(did==l)
		{
			ans[i]='L';
			l++;
		}
		else
		{
			ans[i]='R';
			r--;
		}
		cnt++;
		av[did]=2;
		bk[a[did]]=i;
		int nx=sm(did);
		if(!bk[a[nx-1]])av[sm(nx-1)]=1;
		if(!bk[a[nx+1]])av[sm(nx+1)]=1;
	}
	if(cnt==n)
	{
		for(int i=1;i<=n;i++)
		{
			if(bk[a[l]]==n-i+1)
			{
				ans[i+n]='L';
				l++;
			}
			else
			{
				ans[i+n]='R';
				r--;
			}
		}
		return 1;
	}
	return 0;
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		nn=n*2;
		for(int i=1;i<=n;i++)tp[i]=0;
		for(int i=1;i<=nn;i++)
		{
			scanf("%d",&a[i]);
			id[a[i]][tp[a[i]]++]=i;
		}
//		for(int i=1;i<=n;i++)
//			printf("%d:%d,%d\n",i,id[i][0],id[i][1]);
		if(run(1))printf("%s\n",&ans[1]);
		else if(run(nn))printf("%s\n",&ans[1]);
		else printf("-1\n");
	}
	return 0;
}
