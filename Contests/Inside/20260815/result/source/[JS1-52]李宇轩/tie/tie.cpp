#include<bits/stdc++.h>
using namespace std;
int n,b[200005];
struct node
{
	int x,y,ans;
}a[200005];
bool cmp1(node x,node y)
{
	return x.x<y.x;
}
bool cmp2(node x,node y)
{
	return x.y<y.y;
}
priority_queue<int> q,q1;
int main()
{
	freopen("tie.in","r",stdin);
	freopen("tie.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n+1;i++)
	{
		scanf("%d",&a[i].x);
		a[i].y=i;
	}
	for(int i=1;i<=n;i++)
		scanf("%d",&b[i]);
	sort(a+1,a+n+2,cmp1);
	sort(b+1,b+n+1);
	for(int i=1;i<=n;i++)
	{
		q.push(max(a[i+1].x-b[i],0));
	}
	a[1].ans=q.top();
	for(int i=1;i<=n;i++)
	{
		q1.push(max(a[i+1].x-b[i],0));
		q.push(max(a[i].x-b[i],0));
		while(!q1.empty()&&q1.top()==q.top())
		{
			q1.pop(),q.pop();
		}
		a[i+1].ans=q.top();
	}
	sort(a+1,a+n+2,cmp2);
	for(int i=1;i<=n+1;i++)
	{
		printf("%d ",a[i].ans);
	}
	return 0;
}
