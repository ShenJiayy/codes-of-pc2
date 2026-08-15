#include <bits/stdc++.h>
#define ll long long

using namespace std;

class Tie {
public: ll v, id;
};

ll n, b[200010], sum[200010], sum1[200010], ans[200010], maxx[200010], rev[200010];
Tie a[200010];

int main() {
	freopen("tie.in", "r", stdin);
	freopen("tie.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> n;
	
	for (ll i = 1; i <= n + 1; i++) cin >> a[i].v, a[i].id = i;
	
	sort(a + 1, a + n + 2, [](Tie _x, Tie _y) {
		return _x.v < _y.v;
	});
	
	for (ll j = 1; j <= n; j++) cin >> b[j];
	
	sort(b + 1, b + n + 1);
	
	for (ll i = 1; i <= n; i++) maxx[i] = max(maxx[i - 1], max(a[i].v - b[i], 0ll));
	
	for (ll i = n; i >= 1; i--) rev[i] = max(rev[i + 1], max(a[i + 1].v - b[i], 0ll));
	
	for (ll i = 1; i <= n + 1; i++) ans[a[i].id] = max(maxx[i - 1], rev[i]);

	for (ll i = 1; i <= n + 1; i++) cout << ans[i] << ' ';

	return 0;
}

