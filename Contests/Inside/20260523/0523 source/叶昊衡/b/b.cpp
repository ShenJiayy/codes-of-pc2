#include<bits/stdc++.h>
using namespace std;
int n,num,a[500005];
vector<int>len;
int main()
{
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		if(i==1) num++;
		else if(a[i]==a[i-1]) num++;
		else
		{
			len.push_back(num);
			num=1;
		}
		if(i==n) len.push_back(num);
	}
	int sum=0,le,ans=1e9,id;
	for(int l:len)
	{
		sum+=l;
		le=n-sum;
		int dt=abs(sum-le);
		if(dt<=ans)
		{
			ans=dt;
			id=sum+1;
		}
	}
	cout<<a[id];
}
