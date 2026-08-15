#include<bits/stdc++.h>
using namespace std;
int h,w,q,c[550][550],b[550][550];
int main()
{
	freopen("mask.in","r",stdin);
	freopen("mask.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>h>>w>>q;
	for(int i=1;i<=q;i++)
	{
		int o,x,y,d;
		cin>>o>>x>>y;
		if(o==1)
		{
			cin>>d;
			if(b[x][y]!=-1) c[x][y]=d;
			if(b[x+1][y]!=-1) c[x+1][y]=d;
			if(b[x][y+1]!=-1) c[x][y+1]=d;
			if(b[x+1][y+1]!=-1) c[x+1][y+1]=d;
		}
		else
		{
			b[x][y]=b[x+1][y]=b[x][y+1]=b[x+1][y+1]=-1;
		}
	}
	for(int i=1;i<=h;i++)
	{
		for(int j=1;j<=w;j++) cout<<c[i][j]<<' ';
		cout<<endl;
	}
	return 0;
}
