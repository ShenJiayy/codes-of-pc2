#include<bits/stdc++.h>
using namespace std;
const int N=505;
int n,m,q,cl[N][N],bk[N][N],dx[4]={0,1,0,1},dy[4]={0,0,1,1};
int main()
{
	freopen("mask.in","r",stdin);
	freopen("mask.out","w",stdout);
	scanf("%d%d%d",&n,&m,&q);
	int k,x,y,c;
	while(q--)
	{
		scanf("%d%d%d",&k,&x,&y);
		if(k==1)
		{
			scanf("%d",&c);
			for(int i=0;i<4;i++)
			{
				int xx=x+dx[i],yy=y+dy[i];
				if(!bk[xx][yy])cl[xx][yy]=c;
			}
		}
		else
		{
			for(int i=0;i<4;i++)
			{
				int xx=x+dx[i],yy=y+dy[i];
				bk[xx][yy]=1;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			printf("%d ",cl[i][j]);
		}
		printf("\n");
	}
	return 0;
}
