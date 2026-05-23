#include <bits/stdc++.h>
using namespace std;
int main() 
{
	freopen("d.in","r",stdin);freopen("d.out","w",stdout);
	int n,q;
	cin>>n>>q;
	int a[300010];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long sum=0;
	for(int i=1;i<=n;i++)
	{
		sum+=a[i];
	}
	long long dfg=sum;
	while(q--)
	{
		int c,d;
		cin>>c>>d;
		int s[300010];
		for(int i=1;i<=n;i++)
		{
			s[i]=a[i]/d;
		}
		int k=0,cnt=0;
		int ps=sum;
		//cout<<q<<" ";
		while(ps>=sum)
		{
			k++;
			ps=sum;
			sum+=c;
			while(s[cnt+1]<k)
			{
				cnt++;
				sum-=(a[cnt]-k*d+d);
			}
			sum-=(n-cnt)*d;
			//cout<<ps<<" "<<sum<<" ";
		}
		cout<<ps<<"\n";
		sum=dfg;
	}
    return 0;
}

