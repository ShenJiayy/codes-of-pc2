#include <bits/stdc++.h>
using namespace std;

int n,m,ans = 1e9;
struct Node
{
	int l,r,len;
}q[500005];

int main()
{
	freopen("interval.in","r",stdin);
	freopen("interval.out","w",stdout);
	
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> q[i].l >> q[i].r;
		q[i].len = q[i].r-q[i].l;
	}
	if(m == 2)
	{
		for(int i = 1;i <= n;i++)
		{
			for(int j = 1;j <= n;j++)
			{
				if(i == j) continue;
				if(q[i].l<=q[j].r && q[j].l<=q[i].r)
					ans = min(ans,abs(q[i].len-q[j].len));
			}
		}
		cout << ans;
	}
	else
		cout << -1;
		
	fclose(stdin);
	fclose(stdout);
	return 0;
}
