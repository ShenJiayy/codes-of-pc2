#include<bits/stdc++.h>
using namespace std;
priority_queue<int> str[7];
int n,p,ans;
int main()
{
	freopen("gitara.in","r",stdin);
	freopen("gitara.out","w",stdout);
	cin>>n>>p;
	for(int i=1;i<=n;i++)
	{
		int x,y;
		cin>>x>>y;
		if(str[x].empty())
		{
			str[x].push(y);
			ans++;
			continue;
		}
		while(!str[x].empty())
		{
			if(str[x].top()>y)
			{
				str[x].pop();
				ans++;
				continue;
			}
			break;
		}
		if(str[x].empty()||str[x].top()!=y)
		{
			str[x].push(y);
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
