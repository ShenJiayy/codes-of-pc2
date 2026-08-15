#include <bits/stdc++.h>
using namespace std;

int n,maxn[200005],ans[200005],b[200005];
struct Node
{
	int num,id;
}a[200005];

bool cmp(Node x,Node y)
{
	return x.num<y.num;
}

int main()
{
	freopen("tie.in","r",stdin);
	freopen("tie.out","w",stdout);
	
	cin >> n;
	for(int i = 1;i <= n+1;i++)
	{
		cin >> a[i].num;
		a[i].id = i;
	}
	for(int i = 1;i <= n;i++)
		cin >> b[i];
	sort(a+1,a+n+2,cmp);
	sort(b+1,b+n+1);
	for(int i = 1;i <= n+1;i++)
		maxn[i] = -2e9;
	for(int i = 1;i <= n+1;i++)
	{
		for(int j = 1;j < i;j++)
			maxn[i] = max(maxn[i],max(a[j].num-b[j],0));
		for(int j = i+1;j <= n+1;j++)
			maxn[i] = max(maxn[i],max(a[j].num-b[j-1],0));
	}
	for(int i = 1;i <= n+1;i++)
		ans[a[i].id] = maxn[i];
	for(int i = 1;i <= n+1;i++)
		cout << ans[i] << " ";
		
	fclose(stdin);
	fclose(stdout);
	return 0;
}
