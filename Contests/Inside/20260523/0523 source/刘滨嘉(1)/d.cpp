#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,q,a[300005],qz[300005],minn=LONG_LONG_MAX,cc;
signed main()
{
	freopen("d.in","r",stdin);
	freopen("d.out","w",stdout);
	cin >> n >> q;
	for(int i=1; i<=n; i++)
	{
		cin >> a[i];
		cc+=a[i];
	}
	minn=cc;
	for(int i=1; i<=q; i++)
	{
		int c,d;
		cin >> c >> d;
		int s=0;
		for(int j=1; j<=cc/d+1; j++)
		{
			for(int k=1; k<=n; k++)
			{
				if(0>a[k]-d*j) s+=0;
				else s+=a[k]-d*j;
			}
			s+=c*j;
			if(s<minn) minn=s;
			else break;
		}
		cout << minn << endl;
		minn=cc;
	}
	return 0;
 } 
