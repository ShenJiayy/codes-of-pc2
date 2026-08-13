#include<bits/stdc++.h>
using namespace std;
const int P=5e5+5;
int n,p,stk[10][P],tp[10];
int main()
{
	freopen("gitara.in","r",stdin);
	freopen("gitara.out","w",stdout); 
	scanf("%d%d",&n,&p);
	int x,y,ans=0;
	while(n--)
	{
		scanf("%d%d",&x,&y);
		while(stk[x][tp[x]]>y)
		{
			tp[x]--;
			ans++;
		}
		if(stk[x][tp[x]]<y)
		{
			stk[x][++tp[x]]=y;
			ans++;
		}
	}
	printf("%d",ans);
	return 0;
}
