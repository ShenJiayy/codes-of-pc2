#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll n, p, ans;
bool book[7][300010];

stack<ll> s[10];

int main() {
	freopen("gitara.in", "r", stdin);
	freopen("gitara.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> p;

	while (n--) {
		ll x, y;
		cin >> x >> y;
		if (book[x][y]) continue;
		while (!s[x].empty() && s[x].top() > y) book[x][s[x].top()] = false, s[x].pop(), ans++;
		s[x].push(y), ans++, book[x][y] = true;
	}
	
	cout << ans;
	
	return 0;
}


