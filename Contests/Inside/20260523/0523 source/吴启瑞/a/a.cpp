#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin >> n;
	string s;
	cin >> s;
	for (int i = 1; i < s.size(); i++)
	{
		if (s[i] == 'O' && s[i - 1] == 'J' && s[i + 1] == 'I')
		{
			s[i - 1] = 'O', s[i] = 'I', s[i + 1] = 'J';
		}
	} 
	cout << s;
	return 0;
} 
