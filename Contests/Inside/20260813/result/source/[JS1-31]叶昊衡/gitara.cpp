#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,p;
priority_queue<int>q[7];
int ans=0;
signed main()
{
	freopen("gitara.in","r",stdin);
	freopen("gitara.out","w",stdout);
	cin>>n>>p;
	for(int k=1;k<=n;k++)
	{
		int i,j;
		cin>>i>>j;
		if(q[i].empty())
		{
			q[i].push(j);
			ans++;
		}
		else
		{
			while(!q[i].empty()&&q[i].top()>j)
			{
				q[i].pop();
				ans++;
			}
			if(q[i].empty())
			{
				q[i].push(j);
				ans++;
			}
			else if(q[i].top()<j)
			{
				q[i].push(j);
				ans++;
			}
		}
	}
	cout<<ans;
}
