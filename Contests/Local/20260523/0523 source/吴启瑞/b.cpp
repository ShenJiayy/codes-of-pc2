#include <bits/stdc++.h>
using namespace std;

bool cmp(int a, int b) 
{
	return a > b;
}

int main()
{
//	freopen("b.in", "r", stdin);
//	freopen("b.out", "w", stdout);
	
	int n;
	cin >> n;
	int a[100005];
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + 1 + n, cmp);
	int mnDiff = abs(1 - (n - 1)), best = 1;
	for (int k = 2; k < n; k++)
	{
		int diff = abs(k - (n - k));
		if (diff < mnDiff || (diff == mnDiff && a[k] < a[best]))
		{
			mnDiff = diff;
			best = k;
		}
	}
	cout << a[best - 1];

	return 0;
}
