#include <bits/stdc++.h>
#define ll __int128

using namespace std;

map<ll, pair<ll, bool> > sl;

ll n, m, c, k, a[1000010], mask, am, ans = 1;

ll read() {
	ll _x = 0; char _c = getchar();
	while (_c > '9' || _c < '0') _c = getchar();
	while (_c >= '0' && _c <= '9') _x = _x * 10 + _c - '0', _c = getchar();
	return _x;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	freopen("zoo.in", "r", stdin);
	freopen("zoo.out", "w", stdout);
	
	n = read(), m = read(), c = read(), k = read();

	for (ll i = 1; i <= n; i++) a[i] = read(), am |= a[i];
	
	for (ll i = 1; i <= m; i++) {
		ll p, q;
		p = read(), q = read();
		sl[q].first |= (1ull << p);
		sl[q].second = false;
	}
	
	for (auto & p : sl) {
		if (p.second.first & am) p.second.second = true;
	}
	
	for (auto p : sl) 
		if (!p.second.second) mask |= p.second.first;
		
	for (ll i = 0; i < k; i++) 
		if (!((1 << i) & mask)) ans *= 2ull;
	
	ans -= n;
	
	string _s;
	
	while (ans > 0) {
		_s += (ans % 10) + '0';
		ans /= 10;
	}
	
	reverse(_s.begin(), _s.end());
	
	cout << _s;
	
	return 0;
}


