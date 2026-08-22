#include <bits/stdc++.h>
using namespace std;

int n,m,c,k,cnt,a[1000005],p[1000005],q[1000005];
long long ans;
bool f[65],b[65];

int main()
{
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	
	cin >> n >> m >> c >> k;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
		for(int j = 0;j < k;j++)
			if(a[i]&(1<<j))
				f[j] = 1;
	}
	for(int i = 1;i <= m;i++)
	{
		cin >> p[i] >> q[i];
		if(f[p[i]]==1 && b[p[i]]==0) cnt++;
		b[p[i]] = 1;
	}
	for(int i = 0;i < k;i++)
		if(b[i] == 0)
			cnt++;
	ans = pow(2,cnt)-n;
	cout << ans;
	
	fclose(stdin);
	fclose(stdout);	
	return 0;
}
