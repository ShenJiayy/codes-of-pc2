#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll MAXN = 200010;

class Neb {
	public: ll x, e, in;
	friend bool operator == (Neb a, Neb b) {
		return a.x == b.x && a.e == b.e;
	}
};

ll n, ans;

bool book[MAXN];

vector<ll> E[MAXN];

queue<ll> q;
Neb ns[MAXN];

int main() {
	freopen("ad.in", "r", stdin);
	freopen("ad.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;
	
	for (ll i = 1; i <= n; i++) 
		cin >> ns[i].x >> ns[i].e;
	
	for (ll i = 1; i <= n; i++) 
		for (ll j = 1; j <= n; j++) {
			if (i == j) continue;
			if (llabs(ns[i].x - ns[j].x) <= ns[i].e - ns[j].e) E[i].push_back(j), ns[j].in++;
		}
	
	for (ll i = 1; i <= n; i++) if (ns[i].in == 0) q.push(i);
	
	while (!q.empty()) {
		ll h = q.front();
		q.pop();
		for (ll y : E[h]) if (--ns[y].in == 0) q.push(y), book[y] = true;
	}
	
	for (ll i = 1; i <= n; i++) if (!book[i]) ans++;
	
	cout << ans;

	return 0;
}


