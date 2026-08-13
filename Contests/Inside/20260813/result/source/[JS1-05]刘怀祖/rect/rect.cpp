#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=505,N2=250005,D=250000*11,S=5500005;
int n,m,a[N][N],s[N][N];
int cnt[S];
int main()
{
	freopen("rect.in","r",stdin);
	freopen("rect.out","w",stdout);
	bool fl=0;
	scanf("%d%d",&n,&m);
	if(n>m)fl=1;
	int k;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			scanf("%d",&k);
			if(fl)a[j][i]=k;
			else a[i][j]=k;
		}
	if(fl)swap(n,m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			s[i][j]=s[i-1][j]-s[i-1][j-1]+s[i][j-1]+a[i][j]-1;
	ll ans=0;
	cnt[D]=1;
	for(int l=1;l<=n;l++)
	{
		for(int r=l;r<=n;r++)
		{
			for(int i=1;i<=m;i++)
			{
				int nw=s[r][i]-s[l-1][i];
				ans+=cnt[nw+D];
				cnt[nw+D]++;
			}
			for(int i=1;i<=m;i++)
				cnt[s[r][i]-s[l-1][i]+D]--;
		}
	}
	printf("%lld",ans);
	return 0;
}
