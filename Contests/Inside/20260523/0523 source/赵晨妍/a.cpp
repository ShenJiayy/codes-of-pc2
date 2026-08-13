#include <bits/stdc++.h>
using namespace std;

int n,cnt; 
string s;

int main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	
	vector<char> stk;
	cin >> n >> s;
	for(char c:s)
	{
		stk.push_back(c);
		while(stk.size() >= 3)
		{
			int len = stk.size();
			if(stk[len-3]=='J' && stk[len-2]=='O' && stk[len-1]=='I')
			{
				stk.pop_back();
				stk.pop_back();
				stk.pop_back();
				stk.push_back('O');
				stk.push_back('I');
				cnt++;
			}
			else
			{
				for(int i = 1;i <= cnt;i++)
					stk.push_back('J');
				cnt = 0;
				break;
			}
		}
	}
	for(char c:stk)
		cout << c;
			
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
