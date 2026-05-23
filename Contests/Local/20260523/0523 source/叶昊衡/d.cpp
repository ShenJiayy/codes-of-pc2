#include<bits/stdc++.h>
using namespace std;
int n,q,c,d,a[300005];
long long fs[300005];
int main()
{
	freopen("d.in","r",stdin);
	freopen("d.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) fs[i]=fs[i-1]+a[i];
	while(q--)
	{
		cin>>c>>d;
		int top=(a[n]+d-1)/d;
		long long sum=1e18;
		for(int k=0;k<=top;k++)
		{
			long long x=d*k;
			int l=1,r=n,mid,ans;
			while(l<=r)
			{
				mid=(l+r)/2;
				if(a[mid]>x)
				{
					ans=mid;
					r=mid-1;
				}
				else l=mid+1;
			}
			long long cost=fs[n]-fs[ans-1]-(long long)x*(n-ans+1)+c*k;
			sum=min(sum,cost);
		}
		cout<<sum<<endl;
	}
}
