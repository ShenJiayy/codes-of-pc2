#include <bits/stdc++.h>
using namespace std;
int n, ind;
int a[500010]; 

int main()
{
	freopen("b.in", "r", stdin);
	freopen("b.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	ind = (n + 1) / 2;
	int ind1 = ind, ind2 = ind;
	while (ind1 < n && a[ind1] == a[ind1+1])
	{
		ind1++;
	}
	while (ind2 > 0 && a[ind2] == a[ind2+1])
	{
		ind2--;
	}
	if (n-ind1-ind1 >= ind2 - (n - ind2))
	{
		cout << a[++ind1];
	}
	else
	{
		cout << a[++ind2];
	}
	return 0;
}
