#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,ans;
vector<vector<int> >a,fsum;
signed main()
{
	freopen("rect.in","r",stdin);
	freopen("rect.out","w",stdout);
	cin>>n>>m;
	a.resize(n+10);
	for(int i=1;i<=n;i++)
			a[i].resize(m+10,0);
	for(int i=1;i<=n;i++)
		for(int j=1,aa;j<=m;j++)
			cin>>a[i][j];
	if(n<=30&&m<=30)
	{
		fsum.resize(n+10);
		for(int i=0;i<=n;i++)
			fsum[i].resize(m+10,0);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				fsum[i][j]=fsum[i-1][j]+fsum[i][j-1]-fsum[i-1][j-1]+a[i][j];
		for(int i=1;i<=n;i++)
			for(int j=1;j<=i;j++)
				for(int p=1;p<=m;p++)
					for(int q=1;q<=p;q++)
					{
						int sum=fsum[i][p]-fsum[i][q-1]-fsum[j-1][p]+fsum[j-1][q-1];
						if(sum==(i-j+1)*(p-q+1)) ans++;
					}
		cout<<ans;
		return 0;
	}
	if(n==1)
	{
		
	}
}
