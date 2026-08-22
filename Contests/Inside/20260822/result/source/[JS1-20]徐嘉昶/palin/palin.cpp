#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[100005];
int n;
vector<int> ans;
signed main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int T;
	cin>>T;
	while(T--)
	{
		cin>>n;
		for(int i=1;i<=2*n;i++)
		{
			cin>>a[i];
		}
		bool xjc=0;
		int maxnnn=1ll<<(n*2);
		for(int i=0;i<maxnnn;i++)
		{
			ans.clear();
			ans.push_back(0);
			int l=1,r=2*n;
			for(int k=1;k<=2*n;k++)
			{
				if(((i>>(2*n-k))&1)==0)
				{
					ans.push_back(a[l]);
					l++;
				}
				else
				{
					ans.push_back(a[r]);
					r--;
				}
			}
			bool f=1;
			for(int k=1;k<=n;k++)
			{
				if(ans[k]!=ans[2*n-k+1])
				{
					f=0;
					break;
				}
			}
			if(f)
			{
				for(int k=1;k<=2*n;k++)
				{
					if(((i>>(2*n-k))&1)==1)
					{
						cout<<"R";
					}
					else
					{
						cout<<"L";
					}
				}
				cout<<"\n";
				xjc=1;
				break;
			}
		}
		if(!xjc) cout<<"-1\n";
	}
	return 0;
}
/*
20
3 5 13 2 19 9 20 6 11 4 10 8 7 17 15 1 18 14 16 18 15 17 7 12 8 10 4 11 6 20 9 19 2 13 3 5 1 14 16 12
*/
