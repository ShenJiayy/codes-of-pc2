#include <bits/stdc++.h>
using namespace std;

int n,p,i,j,ans;
struct Node
{
	bool d[300005];
}g[10];

int main()
{
	freopen("gitara.in","r",stdin);
	freopen("gitara.out","w",stdout);
	
	cin >> n >> p;
	while(n--)
	{
		cin >> i >> j;
		if(g[i].d[j] == 0)
		{
			g[i].d[j] = 1;
			ans++;
			
		}
		for(int k = j+1;k <= p;k++)
		{
			if(g[i].d[k] == 1)
			{
				g[i].d[k] = 0;
				ans++;
			}
		}
	}
	cout << ans;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
