#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N=2e5;
int a[N+4],b[5];

int main()
{
	freopen("jjooii.in","r",stdin);
	freopen("jjooii.out","w",stdout);
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i)
	{
		char c=getchar();
		while(c!='J'&&c!='O'&&c!='I') c=getchar();
		if(c=='J') a[i]=1;
		if(c=='O') a[i]=2;
		if(c=='I') a[i]=3;
		++b[a[i]];
	}
//	if(b[1]<k||b[2]<k||b[3]<k)
//	{
		printf("-1");
		return 0;
//	}
	
}
