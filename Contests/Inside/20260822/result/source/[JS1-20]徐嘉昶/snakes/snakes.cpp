#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
int snk[1000006];
int xxxxkkaann=0;
vector<int> xxkan;
vector<int> fl;
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	int T;
	cin>>T;
	int N;
	while(T--)
	{
		cin>>n;
		if(xxxxkkaann==0)
		{
			N=n;
			for(int i=1;i<=N;i++)
			{
				cin>>snk[i];
			}
			xxxxkkaann=1;
		}
		else
		{
			for(int i=1;i<=n;i++)
			{
				int wei,x;
				cin>>wei>>x;
				snk[wei]=x;
			}
		}
		
		xxkan.clear();
		fl.clear();
		xxkan.push_back(-1000);
		fl.push_back(-1000);
		for(int i=1;i<=N;i++)
		{
			xxkan.push_back(snk[i]);
			fl.push_back(i);
		}
		int l=1,r=N;
		for(int i=1;i<=N;i++)
		{
			int minn=xxkan[l],maxn=xxkan[r];
			int hao=fl[r];
			if((maxn-minn>xxkan[l+1])||(maxn-minn==xxkan[l+1]&&hao>fl[l+1])||i==N-1)
			{
				int weist=lower_bound(xxkan.begin()+l,xxkan.begin()+r+1,maxn-minn)-xxkan.begin();
				int weien=upper_bound(xxkan.begin()+l,xxkan.begin()+r+1,maxn-minn)-xxkan.begin();
				if(weien==weist)
				{
					xxkan.insert(weist+xxkan.begin(),maxn-minn);
					fl.insert(weist+fl.begin(),hao);
					l++;
				}
				else
				{
					int wei=upper_bound(fl.begin()+weist,fl.begin()+weien,hao)-fl.begin();
					xxkan.insert(wei+xxkan.begin(),maxn-minn);
					fl.insert(wei+fl.begin(),hao);
					l++;
				}
				
			}
			else
			{
				break;
			}
		}
		cout<<r-l+1<<"\n";
	}
	return 0;
}
