#include <bits/stdc++.h>
using namespace std;
int a[500005];
map<int,int> p;
int main()
{
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		p[a[i]]=1;
	}
	sort(a+1,a+n+1);
	int mi=1e9+7,m=0,s=1e9;
	for(auto i:p)
	{
		int x=i.first;
		int pt=lower_bound(a+1,a+n+1,x)-a-1;
		int sx=n-pt;
//		cout<<x<<" "<<sx<<" "<<pt<<'\n';
		if(abs(sx-pt)<mi||(abs(sx-pt)==mi&&sx<s))
		{
			mi=abs(sx-pt);
			m=x;
			s=sx;
		}
	}
	cout<<m;
}
