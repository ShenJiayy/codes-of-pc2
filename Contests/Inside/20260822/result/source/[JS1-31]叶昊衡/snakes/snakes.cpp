#include<bits/stdc++.h>
using namespace std;
int t,n,a[10];
int main()
{
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	cin>>t>>n;
	if(n==3)
		for(int i=1,k;i<=t;i++)
		{
			if(i==1) for(int j=1;j<=n;j++) cin>>a[i];
			else
			{
				cin>>k;
				for(int j=1,x,y;j<=k;j++) cin>>x>>y,a[x]=y;
			}
			if(a[3]-a[1]>=a[2]) cout<<1<<endl;
			else cout<<3<<endl;
		}
}
