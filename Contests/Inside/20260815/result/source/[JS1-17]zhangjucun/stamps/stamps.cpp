#include<bits/stdc++.h>
using namespace std;
int n,a[220],b[220],ans;
long long l,t[220];
void dfs(int i,int x)
{
	if(i<=n) 
	{
		x<<=1;
		dfs(i+1,x);
		x|=1;
		dfs(i+1,x);
		return ;
	}
	int t1=1,t2=n,nx=0,nt=0,res=0,d=0;
	//cout<<endl<<x<<endl;
	for(int i=1;i<=n;i++)
	{		
		if(x%2==1)
		{			
			if(d!=2)
			{
				d=2;
				if(nx!=0) nt+=(l-nx)+a[t1];
				else nt+=a[t1];
			}
			else nt+=a[t1]-nx;
			if(nt<=t[t1]) res++;
			nx=a[t1];
			t1++;
		}
		else
		{
			if(d!=1)
			{
				d=1;
				nt+=nx+(l-a[t2]);
			}
			else nt+=nx-a[t2];
			if(nt<=t[t2]) res++;
			nx=a[t2];
			t2--;
		}
		//cout<<t1<<' '<<t2<<' '<<nx<<' '<<nt<<' '<<res<<' '<<d<<endl;
		x/=2;
	}
	//cout<<res<<endl;
	ans=max(ans,res);
}
int main()
{
	freopen("stamps.in","r",stdin);
	freopen("stamps.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>l;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) cin>>t[i];
	dfs(1,0);
	cout<<ans;
	return 0;
}
