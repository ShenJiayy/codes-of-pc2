#include<bits/stdc++.h>
using namespace std;
int s[200005];
int dp[200005][4];
int main()
{
	freopen("jjooii.in","r",stdin);
	freopen("jjooii.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		char c;
		cin>>c;
		if(c=='J') s[i]=1;
		else if(c=='O') s[i]=2;
		else s[i]=3;
	}
	int f1=0,f2=0,f3=0,ans=0,cnt=2147483647;
	for(int j=1;j<=n;j++)
	{
		if(s[j]==1)
		{
			f1=0,f2=0,f3=0,ans=0;
			for(int i=j;i<=n;i++)
			{
				if(f1<k)
				{
					if(s[i]==1)
					{
						f1++;
					}
					else
					{
						ans++;
					}
				}
				else if(f2<k)
				{
					if(s[i]==2)
					{
						f2++;
					}
					else
					{
						ans++;
					}
				}
				else if(f3<k)
				{
					if(s[i]==3)
					{
						f3++;
					}
					else
					{
						ans++;
					}
				}
			}
			if(f1+f2+f3==3*k) cnt=min(ans,cnt);
		}
		
	}
	if(cnt!=2147483647) cout<<cnt;
	else cout<<"-1";
	return 0;
}
