#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll n, m, ans;
vector<vector<ll> > a, sum;

map<ll, ll> book;

vector<ll> v;

int main() {
	freopen("rect.in", "r", stdin);
	freopen("rect.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	
	v.assign(m + 1, 0);
	
	a.assign(n + 1, v), sum.assign(n + 1, v);
	
	for (ll i = 1; i <= n; i++) {
		for (ll j = 1; j <= m; j++) cin >> a[i][j], sum[i][j] = sum[i - 1][j] + sum[i][j - 1] + a[i][j] - sum[i - 1][j - 1];
	}
	
	if (n == 1) {
		for (ll i = 1; i <= m; i++) {
			ll mu = i - sum[1][i];
			book[i - sum[1][i - 1] - 1]++;
			ans += book[mu];
		}
		cout << ans;
	} else {
	
	for (ll i = 1; i <= n; i++) 
		for (ll j = 1; j <= m; j++) 
			for (ll i1 = i; i1 <= n; i1++) 
				for (ll j1 = j; j1 <= m; j1++) 
					if ((i1 - i + 1) * (j1 - j + 1) == sum[i1][j1] - sum[i - 1][j1] - sum[i1][j - 1] + sum[i - 1][j - 1]) ans++;

	cout << ans;
	}

	return 0;
}


