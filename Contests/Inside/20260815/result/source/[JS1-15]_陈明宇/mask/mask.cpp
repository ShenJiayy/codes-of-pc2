#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll h, w, q, a[510][510];

bool tape[510][510];

inline void change(ll x, ll y, ll v) {
	if (!tape[x][y]) a[x][y] = v;
}

inline void change2(ll x, ll y) {
	tape[x][y] = true;
}

int main() {
	freopen("mask.in", "r", stdin);
	freopen("mask.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> h >> w >> q;
	
	while (q--) {
		ll op, x, y, c;
		cin >> op >> x >> y;
		if (op == 1) cin >> c, change(x, y, c), change(x + 1, y, c), change(x, y + 1, c), change(x + 1, y + 1, c);
		else change2(x, y), change2(x + 1, y), change2(x, y + 1), change2(x + 1, y + 1);
	}
	
	for (ll i = 1; i <= h; i++) {
		for (ll j = 1; j <= w; j++) 
			cout << a[i][j] << ' ';
		cout << '\n';
	}

	return 0;
}


