#include<bits/stdc++.h>
using namespace std;
int n,m,q;
int _x[4]={0,1,0,1},_y[4]={0,0,1,1};
int a[505][505],book[505][505];
int main()
{
	freopen("mask.in","r",stdin);
	freopen("mask.out","w",stdout);
	cin >> n >> m >> q;
	while(q--)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		if(x==1)
		{
			int c;
			scanf("%d",&c);
			for(int i=0;i<4;i++)
			{
				y+=_x[i],z+=_y[i];
				if(!book[y][z])
					a[y][z]=c;
				y-=_x[i],z-=_y[i];
			}
		}
		else
		{
			for(int i=0;i<4;i++)
			{
				y+=_x[i],z+=_y[i];
				book[y][z]=1;
				y-=_x[i],z-=_y[i];
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
	return 0;
}
