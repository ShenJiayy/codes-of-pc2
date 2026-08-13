#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int n,q;
vector<ll> a;

ll f(ll d,ll c,ll k)
{
	ll sum = 0;
	for(int i = 0;i < n;i++)
		sum += max(0LL,a[i]-d*k);
	sum += c*k;
	return sum;
}

int main()
{
	freopen("d.in","r",stdin);
	freopen("d.out","w",stdout);
	
	cin >> n >> q;
	a.resize(n);
	for(int i = 0;i < n;i++)
		cin >> a[i];
	while(q--)
	{
		ll c,d;
		cin >> c >> d;
		ll l = 0,r = n;
		while(r-l > 3)
		{
			ll m1 = l+(r-l)/3;
			ll m2 = r+(r-l)/3;
			ll f1 = f(d,c,m1);
			ll f2 = f(d,c,m2);
			if(f1 < f2)
				r = m2;
			else
				l = m1;
		}
		ll ans = 1e18;
		for(ll i = l;i <= r;i++)
			ans = min(ans,f(d,c,i));
		cout << ans << endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
