#include<bits/stdc++.h>
using namespace std;
map <int,int> ed;
int a[200005];
int n;
int main()
{
	freopen("stone.in","r",stdin);
	freopen("stone.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(ed[a[i]]==0)
		{
			ed[a[i]]=i;
		}
		else
		{
			ed[a[i]]=i;
		}
	}
	for(int i=1;i<=n;i=ed[a[i]]+1)
	{
		for(int j=i;j<=ed[a[i]];j++)
		{
			cout<<a[i]<<"\n";
		}
	}
	return 0;
}
