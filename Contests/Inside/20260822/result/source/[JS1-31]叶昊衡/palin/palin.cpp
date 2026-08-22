#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int t,n,a[2*N],b[2*N];
bool haveans;
string ans;
bool check()
{
	for(int i=1,j=2*n;i<=n;i++,j--)
		if(b[i]!=b[j]) return 0;
	return 1;
}
bool Less(string s1,string s2)
{
	for(int i=0;i<s1.size();i++)
	{
		if(s1[i]<s2[i]) return 1;
		if(s1[i]>s2[i]) return 0;
	}
	return 0;
}
string Min(string s1,string s2)
{
	if(Less(s1,s2)) return s1;
	else return s2;
}
void dfs(int l,int r,int num,string now)
{
	if(num==2*n)
	{
		if(check()) haveans=1,ans=Min(ans,now);
		return;
	}
	string lst=now;
	b[num+1]=a[l];
	now+='L';
	dfs(l+1,r,num+1,now);
	b[num+1]=a[r];
	now=lst+'R';
	if(ans[num]!='L')
		dfs(l,r-1,num+1,now);
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		ans="";
		haveans=0;
		for(int i=1;i<=2*n;i++) cin>>a[i],ans+='R';
		dfs(1,2*n,0,"");
		if(haveans) cout<<ans<<endl;
		else cout<<-1<<endl;
	}
}
