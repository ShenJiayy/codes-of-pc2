#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int a[N+4],b[N+4],c[N+4];
map<int,int> mp;
inline int read()
{
	int sum=0;
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
	freopen("stone.in","r",stdin);
	freopen("stone.out","w",stdout);
	int n=read(),sta=1;
	for(int i=1;i<=n;++i) a[i]=read();
	for(int i=1;i<=n;++i) if(mp.find(a[i])==mp.end()) mp.insert(pair<int,int>{a[i],mp.size()+1});
	for(int i=n;i;--i) if(c[mp[a[i]]]==0) c[mp[a[i]]]=i;
	for(int i=1;i<=n;i=sta+1)
	{
		sta=c[mp[a[i]]];
		for(int j=i;j<=sta;++j) printf("%d\n",a[i]);
	}
}

