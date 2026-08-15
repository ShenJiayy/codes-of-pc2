#include<bits/stdc++.h>
using namespace std;
int n,k,ans=1e9;
char c[30];
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
	int l=-1,r=-1;
	string s="";
	for(int i=1;i<=n;i++)
	{
		if(x%2==1) 
		{
			r=i;
			if(l==-1) l=i;
			s=s+c[i];
		}
		x/=2;
	}
	if(s.size()!=3*k) return ;
	for(int i=0;i<s.size();i++)
	{
		if(i/k+1==1&&s[i]!='J') return; 
		if(i/k+1==2&&s[i]!='O') return; 
		if(i/k+1==3&&s[i]!='I') return; 
	}
	ans=min(ans,r-l+1-3*k);
}
int main()
{
	freopen("jjooii.in","r",stdin);
	freopen("jjooii.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++) 
	{
		cin>>c[i];
	}
	dfs(1,0);
	if(ans==1e9) cout<<-1;
	else cout<<ans;
	return 0;
}
