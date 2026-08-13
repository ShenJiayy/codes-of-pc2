#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,stk[N],tp;
struct node{
	int x,e;
}nd[N];
bool cmp(node a,node b)
{
	if(a.x==b.x)return a.e>b.e;
	return a.x<b.x;
}
int main()
{
	freopen("ad.in","r",stdin);
	freopen("ad.out","w",stdout);
	scanf("%d",&n);
	int x,e;
	for(int i=0;i<n;i++)
	{
		scanf("%d%d",&x,&e);
		nd[i]={x,e};
	}
	sort(nd,nd+n,cmp);
	int lst=-0x7fffffff;
	for(int i=0;i<n;i++)
	{
		e=nd[i].e;
		x=nd[i].x;
		if(e+x<=lst)continue;
		int pr=e-x;
		while(tp>0&&pr>=stk[tp])tp--;
		stk[++tp]=pr;
		lst=e+x;
	}
	printf("%d",tp);
	return 0;
}
