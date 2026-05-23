#include <bits/stdc++.h>
using namespace std;

int n;

int main()
{
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	
	cin >> n;
	vector<long long> A(n+2,0);
	for(int i = 1;i <= n;i++)
		cin >> A[i];
	long long ans = 0;
	for(int i = 1;i <= n;i++)
	{
		long long t = min(A[i]/2,A[i+1]);
		ans += t;
		A[i] -= t*2;
		A[i+1] -= t;
		t = min(A[i],A[i+1]/2);
		ans += t;
		A[i] -= t;
		A[i+1] -= t*2;
		ans += A[i]/3;
		A[i] %= 3;
	}	 
	cout << ans;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
