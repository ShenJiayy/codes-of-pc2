#include <bits/stdc++.h>
using namespace std;
int n;
string s;

int main()
{
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	cin >> n >> s;
	if (n <= 100)
	{
		bool flag = 1;
		while (flag)
		{
			flag = 0;
			for (int i = 0; i < n - 2; i++)
			{
				if (s[i] == 'J' && s[i+1] == 'O' && s[i+2] == 'I')
				{
					flag = 1;
					s[i] = 'O', s[i+1] = 'I', s[i+2] = 'J';
				}
			}
		}
		cout << s;
		return 0;
	}
	for (int i = 1; i <= n / 3; i++)
	{
		cout << "OI";
	}
	for (int j = 1; j <= n / 3; j++)
	{
		cout << "J";
	}
}
