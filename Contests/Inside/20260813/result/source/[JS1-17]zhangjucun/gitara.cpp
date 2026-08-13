#include<bits/stdc++.h>
using namespace std;
int n,p,ans;
int q[7][300030],t[7];
int main()
{
	freopen("gitara.in","r",stdin);
	freopen("gitara.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>p;
	for(int i=1;i<=n;i++)
	{
		int x,y;
		cin>>x>>y;
		while(t[x]>0&&q[x][t[x]]>y) 
		{
			t[x]--;
			ans++;
		}
		if(q[x][t[x]]!=y)
		{
			ans++,t[x]++;
			q[x][t[x]]=y;
		}
	}
	cout<<ans;
	return 0;
}
