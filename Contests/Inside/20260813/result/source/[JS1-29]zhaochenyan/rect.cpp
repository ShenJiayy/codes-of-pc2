#include <bits/stdc++.h>
using namespace std;

int n,m,sum,cnt,a[250005];

int main()
{
	freopen("rect.in","r",stdin);
	freopen("rect.out","w",stdout);
	
	cin >> n >> m;
	if(n == 1)
	{
		for(int i = 1;i <= m;i++)
			cin >> a[i];
		for(int i = 1;i <= m;i++)
		{
			sum = 0;
			for(int j = i;j <= m;j++)
			{
				sum += a[j];
				if(sum == j-i+1)
					cnt++;
			}
		}
		cout << cnt;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
