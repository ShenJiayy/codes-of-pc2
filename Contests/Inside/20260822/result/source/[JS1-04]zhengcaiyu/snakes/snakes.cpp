#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N=1e6+4;
int a[N<<1],b[N],n,z1,z2,heap1[N<<1],heap2[N<<1];//1sma2big
inline int read()
{
	int sum=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0')
	{
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		sum=sum*10+c-'0';
		c=getchar();
	}
	return sum*f;
}
void del1()
{
	swap(heap1[1],heap1[z1]);
	--z1;
	int now=1;
	while(now<=z1)
	{
		int l=now<<1,r=now<<1|1,k=now;
		if(l<=z1&&(a[heap1[k]]>a[heap1[l]]||(a[heap1[k]]==a[heap1[l]]&&heap1[k]>heap1[l]))) k=l;
		if(r<=z1&&(a[heap1[k]]>a[heap1[r]]||(a[heap1[k]]==a[heap1[r]]&&heap1[k]>heap1[r]))) k=r;
		if(k==now) break;
		swap(heap1[now],heap1[k]);
		now=k;
	}
}
void del2()
{
	swap(heap2[1],heap2[z2]);
	--z2;
	int now=1;
	while(now<=z2)
	{
		int l=now<<1,r=now<<1|1,k=now;
		if(l<=z2&&(a[heap2[k]]<a[heap2[l]]||(a[heap2[k]]==a[heap2[l]]&&heap2[k]<heap2[l]))) k=l;
		if(r<=z2&&(a[heap2[k]]<a[heap2[r]]||(a[heap2[k]]==a[heap2[r]]&&heap2[k]<heap2[r]))) k=r;
		if(k==now) break;
		swap(heap2[now],heap2[k]);
		now=k;
	}
}
void add1(int x)
{
	heap1[++z1]=x;
	int now=z1;
	while(now>=1)
	{
		int l=now>>1,k=now;
		if(l>=1&&(a[heap1[k]]<a[heap1[l]]||(a[heap1[k]]==a[heap1[l]]&&heap1[k]<heap1[l]))) k=l;
		if(k==now) break;
		swap(heap1[now],heap1[k]);
		now=k;
	}
}
void add2(int x)
{
	heap2[++z2]=x;
	int now=z2;
	while(now>=1)
	{
		int l=now>>1,k=now;
		if(l>=1&&(a[heap2[k]]>a[heap2[l]]||(a[heap2[k]]==a[heap2[l]]&&heap2[k]>heap2[l]))) k=l;
		if(k==now) break;
		swap(heap2[now],heap2[k]);
		now=k;
	}
}
int main()
{
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	int T=read();
	n=read();
	for(int i=1;i<=n;++i) a[i]=b[i]=read();
	if(n==3)
	{
		if(a[3]-a[1]>=a[2]) cout<<"1\n";
		else cout<<"3\n";
		while(--T)
		{
			int k=read();
			while(k--)
			{
				int x=read(),y=read();
				a[x]=y;
			}
			if(a[3]-a[1]>=a[2]) cout<<"1\n";
			else cout<<"3\n";
		}
		return 0;
	}
	int now=n,m=n;
	for(int i=1;i<=n;++i)
	{
		add1(i);
		add2(i);
	}
	while(now>1)
	{
		int p=heap1[1],q=heap2[1];
		del1();
		del2();
		if(a[q]-a[p]<a[heap1[1]]||(a[q]-a[p]==a[heap1[1]]&&q>heap2[1])) break;
		a[++m]=a[q]-a[p];
		add1(m);
		add2(m);
		--now;
	}
	printf("%d\n",now);
	while(--T)
	{
		int k=read();
		while(k--)
		{
			int x=read(),y=read();
			b[x]=y;
		}
		for(int i=1;i<=n;++i) a[i]=b[i];
		m=now=n;
		z1=z2=0;
		for(int i=1;i<=n;++i)
		{
			add1(i);
			add2(i);
		}
		while(now>1)
		{
			int p=heap1[1],q=heap2[1];
			del1();
			del2();
			if(a[q]-a[p]<a[heap1[1]]||(a[q]-a[p]==a[heap1[1]]&&q>heap2[1])) break;
			a[++m]=a[q]-a[p];
			add1(m);
			add2(m);
			--now;
		}
		printf("%d\n",now);
	}
}
