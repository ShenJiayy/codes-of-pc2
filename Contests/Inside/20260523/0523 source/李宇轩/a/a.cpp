#include<bits/stdc++.h>
using namespace std;
string a;
int n;
int main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	cin >> n;
	cin >> a;
	for(int i=0;i<n;i++)
	{
		int i1=i;
		for(;i1<n;i1++)
		{
			if(a[i1]=='O'&&a[i1+1]=='I')
			{
				cout << "OI";
				i1++;
				i+=2;
				continue;
			}
			if(a[i1]=='J')
			{
				continue;
			}
			break;
		}
		for(;i<i1;i++)
		{
			cout << 'J';
		}
		cout << a[i1];
		i=i1;
	}
	return 0;
}
