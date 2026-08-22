#include <bits/stdc++.h>
using namespace std;

int t,n,k;

struct Node
{
	int p,id;
}a[1000005];

bool cmp(Node x,Node y)
{
	if(x.p == y.p) return x.id < y.id;
	return x.p < y.p;
}

int main()
{
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	
	cin >> t >> n;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i].p;
		a[i].id = i;
	}
	if(n == 3)
	{
		sort(a+1,a+n+1,cmp);
		if(a[n].p-a[1].p>a[2].p || (a[n].p-a[1].p==a[2].p&&a[n].id>a[2].id))
			cout << 1 << endl;
		else
			cout << 3 << endl;
		cin >> k;
		for(int i = 1,x,y;i <= k;i++)
		{
			cin >> x >> y;
			a[x].p = y;
		}
		sort(a+1,a+n+1,cmp);
		if(a[n].p-a[1].p>a[2].p || (a[n].p-a[1].p==a[2].p&&a[n].id>a[2].id))
			cout << 1;
		else
			cout << 3;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
