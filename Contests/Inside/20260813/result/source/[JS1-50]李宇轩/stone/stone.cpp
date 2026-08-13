#include<bits/stdc++.h>
using namespace std;
int n,a[100005],r[100005];
unordered_map<int,int> mp;
int main()
{
	freopen("stone.in","r",stdin);
	freopen("stone.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(mp[a[i]]!=0)
		{
			r[mp[a[i]]]=i;
		}
		mp[a[i]]=i;
	}
	for(int i=1;i<=n;i++)
	{
		if(r[i]!=0)
		{
			int fl=i;
			for(;i<=r[fl];i++)
				printf("%d\n",a[fl]);
			i--;
		}
		else
			printf("%d\n",a[i]);
	}
	return 0;
}
