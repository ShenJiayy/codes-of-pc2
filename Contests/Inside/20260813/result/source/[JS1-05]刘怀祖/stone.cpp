#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,a[N],v[N],ans[N];
vector<int> ps[N];
int main()
{
	freopen("stone.in","r",stdin);
	freopen("stone.out","w",stdout);
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		v[i]=a[i];
	}
	sort(v,v+n);
	int nn=unique(v,v+n)-v;
	for(int i=0;i<n;i++)
	{
		a[i]=lower_bound(v,v+nn,a[i])-v;
		ps[a[i]].push_back(i);
	}
	int nw=0;
	while(nw<n)
	{
		int lst=ps[a[nw]][ps[a[nw]].size()-1];
		for(int i=nw;i<=lst;i++)ans[i]=v[a[nw]];
		nw=lst+1;
	}
	for(int i=0;i<n;i++)printf("%d\n",ans[i]);
	return 0;
}
