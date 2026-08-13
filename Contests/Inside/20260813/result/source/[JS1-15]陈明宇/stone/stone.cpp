#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll MAXN = 200010;

ll n, a[MAXN], b[MAXN], book[MAXN], tag[MAXN], pos[MAXN], len, L[MAXN], R[MAXN];
vector<ll> vals;

void init() {
	for (ll i = 1; i <= n; i++) pos[i] = (i - 1) / len + 1;
	for (ll i = 1; i <= pos[n]; i++) L[i] = (i - 1) * len + 1, R[i] = i * len, tag[i] = -1;
}

ll query(ll x) {
	return tag[pos[x]] == -1 ? b[x] : tag[pos[x]];
}

void push_down(ll x) {
	if (tag[x] == -1) return;
	for (ll i = L[x]; i <= R[x]; i++) b[i] = tag[x];
	tag[x] = -1;
}

void modify(ll x, ll y, ll v) {
	ll l = pos[x], r = pos[y], el = L[l + 1] - 1, sr = R[r - 1] + 1;
	if (l == r) {
		push_down(l);
		for (ll i = x; i <= y; i++) b[i] = v;
	} else {
		for (ll i = l + 1; i <= r - 1; i++) tag[i] = v;
		push_down(l);
		for (ll i = x; i <= el; i++) b[i] = v;
		push_down(r);
		for (ll i = sr; i <= y; i++) b[i] = v;
	}
}

int main() {
	freopen("stone.in", "r", stdin);
	freopen("stone.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;
	
	len = (ll) sqrt(n);
	
	
	for (ll i = 1; i <= n; i++) cin >> a[i], vals.push_back(a[i]), book[i] = -1;
	
	sort(vals.begin(), vals.end());
	
	vals.erase(unique(vals.begin(), vals.end()), vals.end());
	
	init();
	
	for (ll i = 1; i <= n; i++) {
		ll posx = lower_bound(vals.begin(), vals.end(), a[i]) - vals.begin() + 1;
		if (book[posx] == -1) {
			book[posx] = i;
			continue;
		}
		ll got = query(book[posx]);
		if (got == 1) {
			book[posx] = i;
			continue;
		}
		if (i - 1 >= book[posx] + 1) modify(book[posx] + 1, i - 1, 1);
	}
	
	ll lst = 0;
	
	for (ll i = 1; i <= n; i++) {
		if (query(i) == 1) cout << lst << '\n';
		else cout << a[i] << '\n', lst = a[i];
	}

	return 0;
}


