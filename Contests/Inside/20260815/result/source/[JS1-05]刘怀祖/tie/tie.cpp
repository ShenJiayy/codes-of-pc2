#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,b[N],lmx[N],rmx[N],ans[N];
struct ti{
	int a,id;
}t[N];
bool cmp(ti x,ti y)
{
	return x.a<y.a;
}
int main()
{
	freopen("tie.in","r",stdin);
	freopen("tie.out","w",stdout);
	scanf("%d",&n);
	int a;
	for(int i=0;i<=n;i++)
	{
		scanf("%d",&a);
		t[i]={a,i};
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&b[i]);
	}
	sort(t,t+n+1,cmp);
	sort(b+1,b+n+1);
	for(int i=1;i<=n;i++)lmx[i]=max(t[i-1].a-b[i],lmx[i-1]);
	for(int i=n;i>0;i--)rmx[i]=max(t[i].a-b[i],rmx[i+1]);
	for(int i=0;i<=n;i++)
	{
		ans[t[i].id]=max(lmx[i],rmx[i+1]);
	}
	for(int i=0;i<=n;i++)printf("%d ",ans[i]);
	return 0;
}
