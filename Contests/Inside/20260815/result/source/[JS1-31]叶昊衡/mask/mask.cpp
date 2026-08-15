#include<bits/stdc++.h>
using namespace std;
int h,w,q,col[505][505];
bool gai[505][505];
bool inmap(int x,int y)
{
	return 1<=x&&x<=h&&1<=y&&y<=w;
}
void solve1(int x,int y,int c)
{
	if(inmap(x,y)&&!gai[x][y]) col[x][y]=c; 
}
void solve2(int x,int y)
{
	if(inmap(x,y)) gai[x][y]=1;
}
int main()
{
	freopen("mask.in","r",stdin);
	freopen("mask.out","w",stdout);
	cin>>h>>w>>q;
	while(q--)
	{
		int opt,x,y,c;
		cin>>opt;
		if(opt==1)
		{
			cin>>x>>y>>c;
			int tx=x+1,ty=y+1;
			solve1(x,y,c);
			solve1(tx,ty,c);
			solve1(tx,y,c);
			solve1(x,ty,c);
		}
		else
		{
			cin>>x>>y;
			int tx=x+1,ty=y+1;
			solve2(x,y);
			solve2(tx,ty);
			solve2(tx,y);
			solve2(x,ty);
		}
	}
	for(int i=1;i<=h;i++)
	{
		for(int j=1;j<=w;j++)
			cout<<col[i][j]<<' ';
		cout<<endl;
	}
		
}
