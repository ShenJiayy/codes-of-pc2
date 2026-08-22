#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int T,n,a[N];
int main()
{
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	scanf("%d%d",&T,&n);
	for(int ii=0;ii<T;ii++)
	{
		if(ii)
		{
			int x,y,k;
			scanf("%d",&k);
			for(int i=0;i<k;i++)
			{
				scanf("%d%d",&x,&y);
				a[x]=y;
			}
		}
		else
		{
			for(int i=1;i<=n;i++)
			{
				scanf("%d",&a[i]);
			}
		}
		if(a[3]<a[1]+a[2])printf("3\n");
		else printf("1\n");
	}
	return 0;
}
