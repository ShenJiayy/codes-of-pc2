#include <bits/stdc++.h>
using namespace std;

int n,k,i,j,id,l[200005],r[200005],ans = 1e9;
bool flag = true;
char s[200005];

int main()
{
	freopen{"jjooii.in","r",stdin};
	freopen("jjooii.out","w",stdin);
	
	cin >> n >> k;
	for(int x = 1;x <= n;x++)
		cin >> s[x];
	if(n == 3*k)
	{
		for(int x = 1;x <= k;x++)
			if(s[x] != 'J')
				flag = false;
		for(int x = k+1;x <= 2*k;x++)
			if(s[x] != 'O')
				flag = false;
		for(int x = 2*k+1;x <= 3*k;x++)
			if(s[x] != 'I')
				flag = false;
		if(flag) return cout << 0, 0;
	}
	i = n,j = 1;
	while(i >= 3*k)
	{
		int cnt = 0;
		while(s[i] != 'I')
			i--;
		while(s[j] != 'J')
			j++;
		for(int x = j+1;x < i;x++)
			if(s[x] == 'O')
				cnt++;
		if(cnt >= k)
			l[++id] = j,r[id] = i;
		if(l[k]!=0 && r[k]!=0)
			ans = min(ans,r[id-k+1]-l[id-k+1]+1-3*k);
		i--;
		j++;
	}
	if(ans == 1e9) cout << -1;
	else cout << ans;
	
	fclose(stdin);
	fclose(stdout);
	return 0;	
}
