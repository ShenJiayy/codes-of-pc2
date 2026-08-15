#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[505][505];
bool b[505][505];
signed main()
{
	freopen("mask.in", "r", stdin);
	freopen("mask.out", "w", stdout);
 	int h, w,  q;
 	cin>>h>>w>>q;
 	while(q--)
 	{
 		int op;
 		cin>>op;
 		int x, y;
 		cin>>x>>y;
 		if(op == 1)
 		{
 			int c;
 			cin>>c;
 			if(b[x][y] == 0)
 				a[x][y] = c;
 			if(b[x][y + 1] == 0)
 				a[x][y + 1] = c;
 			if(b[x + 1][y] == 0)
 				a[x + 1][y] = c;
 			if(b[x + 1][y + 1] == 0)
 				a[x + 1][y + 1] = c;
		}
		if(op == 2)
		{
			b[x][y] = 1;
			b[x][y + 1] = 1;
			b[x + 1][y] = 1;
			b[x + 1][y + 1] = 1;
		}
	}
	for(int i = 1; i <= h; i++)
	{
		for(int j = 1; j <= w; j++)
		{
			cout<<a[i][j]<<' ';
		}
		cout<<endl;
	}
	return 0;
}
