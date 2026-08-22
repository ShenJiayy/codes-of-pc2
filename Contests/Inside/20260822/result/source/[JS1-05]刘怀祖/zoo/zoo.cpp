#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
typedef unsigned long long ull;
int n,m,c,k,p,q,nm[16]={0,1,1,2,1,2,2,3,1,2,2,3,2,3,3,4};
ull a[N],bk,lim;
int pcnt(ull x)
{
	int ret=0;
	while(x>0)
	{
		ret+=nm[x&15];
		x>>=4;
	}
	return ret;
}
int main()
{
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	scanf("%d%d%d%d",&n,&m,&c,&k);
	for(int i=0;i<n;i++)
	{
		scanf("%lld",&a[i]);
		bk|=a[i];
	}
	for(int i=0;i<m;i++)
	{
		scanf("%d%d",&p,&q);
		lim|=1<<p;
	}
	int x=k-pcnt(lim^(bk&lim));
	if(x==64&&n==0)
	{
		printf("18446744073709551616");
	}
	else
	{
		printf("%llu",ull((__int128(1)<<x)-n));
	}
	return 0;
}
