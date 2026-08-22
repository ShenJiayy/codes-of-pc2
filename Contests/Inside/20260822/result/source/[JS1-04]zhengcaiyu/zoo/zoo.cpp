#include<bits/stdc++.h>
typedef unsigned long long ull;
using namespace std;
bool sc[70];
int a[30]={0,6,1,6,1,5,5,9,0,7,3,7,0,4,4,7,6,4,4,8,1},b[30];
inline ull read()
{
	ull sum=0;
	char c=getchar();
	while(c>'9'||c<'0') c=getchar();
	while(c>='0'&&c<='9')
	{
		sum=sum*10+c-'0';
		c=getchar();
	}
	return sum;
}
int main()
{
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	ull n=read(),m=read(),c=read(),k=read(),kk=0,p,cnt=0,ss=0;
	for(ull i=1;i<=n;++i) kk|=read();
	while(m--)
	{
		p=read();
		if(!sc[p])
		{
			if((1<<p)&kk) ++ss;
			++cnt;
			sc[p]=true;
		}
		p=read();
	}
	cnt-=ss;
	if(k-cnt==64)
	{
		int z=0;
		while(n)
		{
			b[++z]=n%10;
			n/=10;
		}
		int r=0;
		for(int i=1;i<=20;++i)
		{
			a[i]=a[i]-b[i]-r;
			r=0;
			if(a[i]<0)
			{
				a[i]+=10;
				++r;
			}
		}
		bool f=false;
		for(int i=20;i;--i)
		{
			if(!f&&a[i]!=0)
			{
				cout<<a[i];
				f=true;
			}
			else if(f) cout<<a[i];
		}
		if(!f) cout<<0;
		return 0;
	}
	ull ans=(1<<(k-cnt))-n;
	cout<<ans;
}
