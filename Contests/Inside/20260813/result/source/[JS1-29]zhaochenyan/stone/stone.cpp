#include <bits/stdc++.h>
using namespace std;

int n,k,a[200005];

int main()
{
	freopen("stone.in","r",stdin);
	freopen("stone.out","w",stdout);
	
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		k = n;
		cin >> a[i];
		for(int j = i-1;j >= 1;j--)
		{
			if(a[j] == a[i])
			{
				k = j;
				break;
			}
		}
		for(int j = k+1;j < i;j++)
			a[j] = a[i];
	}
	for(int i = 1;i <= n;i++)
		cout << a[i] << endl;
		
	fclose(stdin);
	fclose(stdout);
	return 0;
}
