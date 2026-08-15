#include<bits/stdc++.h>
using namespace std;
int n,s[400040],r2[400040],c[400040],num[400040],ans[200020];
struct str
{
	int l,id;
}a[200020],b[200020];
bool cmp(str a1,str a2)
{
	return a1.l<a2.l;
}
int lb(int k){return -(k)&k;}
void ud(int k,int d)
{
	while(k<=2*n)
	{
		s[k]+=d;
		k+=lb(k);
	}
}
int que(int k)
{
	int res=0;
	while(k>0)
	{
		res+=s[k];
		k-=lb(k);
	}
	return res;
}
int main()
{
	freopen("tie.in","r",stdin);
	freopen("tie.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n+1;i++) 
	{
		cin>>a[i].l;
		a[i].id=i;
	}
	for(int i=1;i<=n;i++) 
	{
		cin>>b[i].l;
		b[i].id=i;
	}
	sort(a+1,a+n+2,cmp),sort(b+1,b+n+1,cmp);
	for(int i=1;i<=n+1;i++)
	{
		if(i<=n)
		{
			c[i]=max(a[i+1].l-b[i].l,0);
			c[i+n]=max(a[i].l-b[i].l,0);
			num[i]=c[i],num[i+n]=c[i+n];
		}
	}
	sort(c+1,c+2*n+1);
	for(int i=1;i<=2*n;i++) 
	{
		int x=num[i];
		num[i]=lower_bound(c+1,c+2*n+1,x)-c;
		r2[num[i]]=x;
	}
	for(int i=1;i<=n;i++)
	{
		ud(num[i],1);
	}
	for(int i=1;i<=n+1;i++)
	{
		int l=1,r=n*2;
		while(l<=r)
		{
			int mid=(l+r)>>1;
			if(que(mid)==n) r=mid-1;
			else l=mid+1;
		}
		ans[a[i].id]=r2[l];
		if(i<=n)
		{
			ud(num[i],-1);
			ud(num[i+n],1);			
		}
	}
	for(int i=1;i<=n+1;i++) cout<<ans[i]<<' ';
	return 0;
}
