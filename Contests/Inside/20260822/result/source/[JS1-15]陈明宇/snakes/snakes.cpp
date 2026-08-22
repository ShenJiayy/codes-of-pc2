#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll t, n;

class S {
public: ll x, id;
		bool operator < (const S _x) {
			if (x != _x.x) return x > _x.x;
			return id > _x.id;
		}
};

S a[1000010];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	freopen("snakes.in", "r", stdin);
	freopen("snakes.out", "w", stdout);

	cin >> t;
	
	cin >> n;
	
	if (n == 3) {
		for (ll i = 1; i <= n; i++) cin >> a[i].x, a[i].id = i;
		sort(a + 1, a + n + 1);
		ll lst = a[1].x - a[n].x;
		if (lst > a[2].x || (lst == a[2].x && a[1].id > a[2].id)) cout << "1\n";
		else cout << "3\n";
		for (ll i = 1; i < t; i++) {
			ll k; cin >> k;
			for (ll j = 1; j <= k; j++) {
				ll x, y;
				cin >> x >> y;
				a[x].x = y;
			}
			sort(a + 1, a + n + 1);
			lst = a[1].x - a[n].x;
			if (lst > a[2].x || (lst == a[2].x && a[1].id > a[2].id)) cout << "1\n";
			else cout << "3\n";
		}
	}

	return 0;
}


