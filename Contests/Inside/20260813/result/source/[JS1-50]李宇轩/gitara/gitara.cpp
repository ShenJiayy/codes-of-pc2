#include <bits/stdc++.h>
using namespace std;
int n,m,a[7][300005],cnt[7],ans;
void query(int x,int y)
{
	if(cnt[x]==0)
	{
		a[x][++cnt[x]]=y;
		ans++;
	}
	int l=0,r=cnt[x];
	while(l<r)
	{
		int mid=(l+r+1)/2;
		if(a[x][mid]<=y)
			l=mid;
		else
			r=mid-1; 
	}
	ans+=cnt[x]-l;
	cnt[x]=l;
	if(a[x][l]<y)
		a[x][++cnt[x]]=y,ans++;
	return;
}
int main()
{
	freopen("gitara.in","r",stdin);
	freopen("gitara.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		int x,y;
		cin >> x >> y;
		query(x,y);
	}
	cout << ans;
	return 0;
}
