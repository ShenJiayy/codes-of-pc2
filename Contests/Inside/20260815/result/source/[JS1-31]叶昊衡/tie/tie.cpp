#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,b[200005],ans[200005];
int x[200005],y[200005];
struct node{
	int a,id;
	bool operator < (const node &no) const
	{
		return a>no.a;
	}
}p[200005];
bool cmp(int xx,int yy)
{
	return xx>yy;
}
signed main()
{
	freopen("tie.in","r",stdin);
	freopen("tie.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n+1;i++) cin>>p[i].a,p[i].id=i;
	for(int i=1;i<=n;i++) cin>>b[i];
	sort(p+1,p+n+2);
	sort(b+1,b+n+1,cmp);
	for(int i=1;i<=n;i++)
		x[i]=max(x[i-1],max(p[i].a-b[i],(int)0));
	for(int i=n;i>=1;i--)
		y[i]=max(y[i+1],max(p[i+1].a-b[i],(int)0));
	for(int i=1;i<=n+1;i++)
		ans[p[i].id]=max(x[i-1],y[i]);
	for(int i=1;i<=n+1;i++)
		cout<<ans[i]<<' ';
}
