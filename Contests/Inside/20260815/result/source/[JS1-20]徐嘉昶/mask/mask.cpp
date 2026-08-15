#include<bits/stdc++.h>
using namespace std;
int mp[505][505];
bool vis[505][505];
int n,m,q;
int main()
{
	freopen("mask.in","r",stdin);
	freopen("mask.out","w",stdout);
	cin>>n>>m>>q;
	while(q--)
	{
		int op,x,y;
		cin>>op>>x>>y;
		if(op==1)
		{
			int c;
			cin>>c;
			if(!vis[x][y]) mp[x][y]=c;
			if(!vis[x+1][y]) mp[x+1][y]=c;
			if(!vis[x][y+1]) mp[x][y+1]=c;
			if(!vis[x+1][y+1]) mp[x+1][y+1]=c;
		}
		else
		{
			vis[x][y]=1;
			vis[x+1][y]=1;
			vis[x][y+1]=1;
			vis[x+1][y+1]=1;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cout<<mp[i][j]<<" ";
		}
		cout<<"\n";
	}
	return 0;
}
