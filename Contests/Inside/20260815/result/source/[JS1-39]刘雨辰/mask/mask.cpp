#include<bits/stdc++.h>
using namespace std;
int a[510][510];bool vis[510][510];
int main()
{
	freopen("mask.in","r",stdin);
	freopen("mask.out","w",stdout);
	int h,w;
	cin>>h>>w;
	int q;
	cin>>q;
	while(q--)
	{
		int op;
		cin>>op;
		if(op==1)
		{
			int x,y,c;
			cin>>x>>y>>c;
			if(!vis[x][y])a[x][y]=c;
			if(!vis[x+1][y+1])a[x+1][y+1]=c;
			if(!vis[x+1][y])a[x+1][y]=c;
			if(!vis[x][y+1])a[x][y+1]=c;
		}
		if(op==2)
		{
			int x,y;
			cin>>x>>y;
			vis[x][y]=1;
			vis[x+1][y+1]=1;
			vis[x+1][y]=1;
			vis[x][y+1]=1;
		}
	}
	for(int i=1;i<=h;i++)
	{
		for(int j=1;j<=w;j++)
		{
			cout<<a[i][j];cout<<" ";
		}
		cout<<"\n";
	}
	return 0;
}

