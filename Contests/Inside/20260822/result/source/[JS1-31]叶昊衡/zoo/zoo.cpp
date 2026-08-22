#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,c,k,a,s,num;
struct node{
	int p,q;
}ask[1000006];
int cpy[1000006];
bool vis[1000006],visk[100];
int f(int a,int b)
{
    int ans=1;
    while(b>0)
    {
        if(b&1) ans*=a;
        a*=a;
        b>>=1;
    }
    return ans;
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	cin>>n>>m>>c>>k;
	num=k;
	for(int i=1;i<=n;i++) cin>>a,s|=a;
	for(int i=1;i<=m;i++)
		cin>>ask[i].p>>ask[i].q,cpy[i]=ask[i].q;
	sort(cpy+1,cpy+m+1);
	int len=unique(cpy+1,cpy+m+1)-cpy-1;
	for(int i=1;i<=m;i++)
		ask[i].q=lower_bound(cpy+1,cpy+len+1,ask[i].q)-cpy;
	for(int i=1;i<=m;i++)
		if((s>>ask[i].p)&1)
			vis[ask[i].q]=visk[ask[i].p]=1;
	for(int i=1;i<=m;i++)
		if(!((s>>ask[i].p)&1))
			if(!vis[ask[i].q]&&!visk[ask[i].p])
				num--,visk[ask[i].p]=1;
	cout<<f(2,num)-n<<endl;
}
/*
2 3 3 4
1 4
0 1
1 2
2 3
*/
