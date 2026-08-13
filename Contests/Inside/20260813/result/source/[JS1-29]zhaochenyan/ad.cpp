#include <bits/stdc++.h>
using namespace std;

int n,cnt = 1,x[500005],e[500005];

int main()
{
	freopen("ad.in","r",stdin);
	freopen("ad.out","w",stdout);
	
	cin >> n;
	for(int i = 1;i <= n;i++)
		cin >> x[i] >> e[i];
	sort(x+1,x+n+1);
	for(int i = 2;i <= n;i++)
		if(x[i] != x[i-1])
			cnt++;
	cout << cnt;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
