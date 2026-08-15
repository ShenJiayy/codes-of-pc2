#include <bits/stdc++.h>
using namespace std;

int h,w,n,q,x,y,c,s[505][505],s2[505][505];

int main()
{
	freopen("mask.in","r",stdin);
	freopen("mask.out","w",stdout);
	
	cin >> h >> w >> n;
	while(n--)
	{
		cin >> q;
		if(q == 1)
		{
			cin >> x >> y >> c;
			if(s2[x][y] != -1)
				s[x][y] = c;
			if(s2[x+1][y] != -1)
				s[x+1][y] = c;
			if(s2[x][y+1] != -1)
				s[x][y+1] = c;
			if(s2[x+1][y+1] != -1)
				s[x+1][y+1] = c;
		}
		else if(q == 2)
		{
			cin >> x >> y;
			s2[x][y] = -1;
			s2[x+1][y] = -1;
			s2[x][y+1] = -1;
			s2[x+1][y+1] = -1;
		}
	}
	for(int i = 1;i <= h;i++)
	{
		for(int j = 1;j <= w;j++)
			cout << s[i][j] << " ";
		cout << endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
