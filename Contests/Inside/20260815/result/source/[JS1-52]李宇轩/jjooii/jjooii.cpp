#include<bits/stdc++.h>
using namespace std;
int n,k,ans=2147483647;
int ch(char x)
{
	return x-'A';
}
struct node
{
	char s;
	int b[27];
}a[200005];
int er(int x,char s,int m)
{
	int l=x,r=n;
	while(l<r)
	{
		int mid=(l+r)/2;
		if(a[mid].b[ch(s)]<a[x].b[ch(s)]+m)
		{
			l=mid+1;
		}
		else
		{
			r=mid;
		}
	}
	if(a[l].b[ch(s)]==a[x].b[ch(s)]+m)
		return l;
	else
		return 0;
}
int main()
{
	freopen("jjooii.in","r",stdin);
	freopen("jjooii.out","w",stdout);
	cin >> n >> k;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i].s;
		a[i].b[ch('J')]=a[i-1].b[ch('J')];
		a[i].b[ch('O')]=a[i-1].b[ch('O')];
		a[i].b[ch('I')]=a[i-1].b[ch('I')];
		a[i].b[ch(a[i].s)]++;
	}
//	for(int i=1;i<=n;i++)
//	{
//		cout << a[i].s << ' ';
//		cout << a[i].b[ch('J')] << ' ';
//		cout << a[i].b[ch('O')] << ' ';
//		cout << a[i].b[ch('I')] << '\n';
//	}
	for(int i=1;i<=n-3*k+1;i++)
	{
		if(a[i].s=='J')
		{
			int s=er(i,'J',k-1);
//			cout << s << ' ';
			if(s)
			{
				int m=er(s,'O',k);
//				cout << m << ' ';
				if(m)
				{
					int e=er(m,'I',k);
//					cout << e << ' ';
					if(e)
					{
//						cout << e-i+1-3*k;
						ans=min(ans,e-i+1-3*k);
					}
				}
			}
//			cout << '\n';
		}
	}
	if(ans==2147483647)
	{
		cout << -1;
		return 0;
	}
	cout << ans;
	return 0;
}
