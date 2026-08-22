#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=100005,M=N,mod=998244353;
int n,m,q,a[N];
struct point{
	int tpe,idx,num,id;
	vector<int>son;
	void in(int i)
	{
		cin>>tpe;
		if(tpe==1) cin>>idx>>num;
		else if(tpe==2) cin>>num;
		else
		{
			int siz;cin>>siz;
			for(int j=1,pin;j<=siz;j++)
				cin>>pin,son.push_back(pin);
		}
		id=i;
	}
}tu[M];
void work(int u)
{
	if(tu[u].tpe==3) for(int v:tu[u].son) work(v);
	else if(tu[u].tpe==1) a[tu[u].idx]=(a[tu[u].idx]+tu[u].num)%mod;
	else for(int i=1;i<=n;i++) a[i]=(a[i]*tu[u].num)%mod;
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	cin>>m;
	for(int i=1;i<=m;i++) tu[i].in(i);
	cin>>q;
	for(int i=1,f;i<=q;i++) cin>>f,work(f);
	for(int i=1;i<=n;i++) cout<<a[i]<<' ';
}
