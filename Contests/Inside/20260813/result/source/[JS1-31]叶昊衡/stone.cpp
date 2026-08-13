#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a,col[200005];
unordered_map<int,int>last;
signed main()
{
	freopen("stone.in","r",stdin);
	freopen("stone.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>col[i],last[col[i]]=i;
	for(int i=1;i<=n;i++)
	{
		int idx=i;
		for(int j=i+1;j<last[col[i]];j++,i++)
			col[j]=col[idx];
	}
	for(int i=1;i<=n;i++)
		cout<<col[i]<<endl;
}
