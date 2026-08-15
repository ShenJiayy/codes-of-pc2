#include <bits/stdc++.h>
#define ll long long

using namespace std;

class Pair {
public: ll x, y, i1, i2;
};

ll n, l, lft[210][210], rgt[210][210], ans;
Pair dp[210][210][2];
bool book[210][210][2];
pair<ll, ll> sta[210];

static ll pre(ll x) {
	return x == 0 ? n : x - 1;
}

static ll nxt(ll x) {
	return x == n ? 0 : x + 1;
}

int main() {
	freopen("stamps.in", "r", stdin);
	freopen("stamps.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> l;
	
	for (ll i = 1; i <= n; i++) cin >> sta[i].first;

	for (ll i = 1; i <= n; i++) cin >> sta[i].second;
	
	sort(sta + 1, sta + n + 1);
	
	//顺时针向左，逆时针向右 
	for (ll i = 1; i <= n; i++) {
		lft[0][i] = rgt[i][0] = sta[i].first, rgt[0][i] = lft[i][0] = l - sta[i].first;
		dp[i][0][1].i2 = dp[0][i][0].i2 = dp[i][0][0].i2 = dp[0][i][1].i2 = i;
		for (ll j = 1; j < i; j++) 
			lft[i][j] = rgt[j][i] = (sta[j].first - sta[i].first + l) % l, rgt[i][j] = lft[j][i] = (sta[i].first - sta[j].first + l) % l;
	}

	sta[0].second = LLONG_MAX;
	
	dp[0][0][0].y = dp[0][0][1].y = 1;

	for (ll i = 0; i <= n; i++) {
		for (ll j = 0; j <= n; j++) {
			if (i == j && i != 0) continue;
			//从左，向右 
			ll il_0 = dp[i][j][0].i1, il_1 = dp[i][j][1].i1, ir_0 = dp[i][j][0].i2, ir_1 = dp[i][j][1].i2, sum = 0;
			if (nxt(ir_0) != il_0 && pre(il_0) != ir_0)
			for (ll l = pre(il_0); l != ir_0; l = pre(l)) {
				if (l == j) continue;
				if (dp[i][j][0].x + lft[l][j] <= sta[l].second) sum++;
				if (dp[j][l][1].y < dp[i][j][0].y + sum)
					dp[j][l][1].x = dp[i][j][0].x + lft[l][j], dp[j][l][1].y = dp[i][j][0].y + sum; 
				ans = max(ans, dp[j][l][1].y);
				dp[j][l][1].i1 = l, dp[j][l][1].i2 = ir_0;
//				cout << "from left: " << i << " now right " << j << " to " << l << " ans: " << ans << '\n';
			}
			//从左，向左 
			sum = 0;
			if (nxt(ir_0) != il_0 && pre(il_0) != ir_0)
			for (ll l = nxt(ir_0); l != il_0; l = nxt(l)) {
				if (l == j) continue;
				if (dp[i][j][0].x + rgt[l][j] <= sta[l].second) sum++;
				if (dp[j][l][0].y < dp[i][j][0].y + sum)
					dp[j][l][0].x = dp[i][j][0].x + rgt[l][j], dp[j][l][0].y = dp[i][j][0].y + sum; 
				ans = max(ans, dp[j][l][0].y);
				dp[j][l][0].i1 = il_0, dp[j][l][0].i2 = l;
//				cout << "from left: " << i << " now left " << j << " to " << l << " ans: " << ans << '\n';
			}
			//从右，向右 
			sum = 0;
			if (nxt(il_1) != ir_1 && pre(ir_1) != il_1)
			for (ll l = pre(il_1); l != ir_1; l = pre(l)) {
				if (l == j) continue;
				if (dp[i][j][1].x + lft[l][j] <= sta[l].second) sum++;
				if (dp[j][l][1].y < dp[i][j][1].y + sum)
					dp[j][l][1].x = dp[i][j][1].x + lft[l][j], dp[j][l][1].y = dp[i][j][1].y + sum; 
				ans = max(ans, dp[j][l][1].y);
				dp[j][l][1].i1 = l, dp[j][l][1].i2 = ir_1;
//				cout << "from right: " << i << " now right " << j << " to " << l << " ans: " << ans << '\n';
			}
			//从右，向左 
			sum = 0;
			if (nxt(il_1) != ir_1 && pre(ir_1) != il_1)
			for (ll l = nxt(ir_1); l != il_1; l = nxt(l)) {
				if (l == j) continue;
				if (dp[i][j][1].x + rgt[l][j] <= sta[l].second) sum++;
				if (dp[j][l][0].y < dp[i][j][1].y + sum)
					dp[j][l][0].x = dp[i][j][1].x + rgt[l][j], dp[j][l][0].y = dp[i][j][1].y + sum; 
				ans = max(ans, dp[j][l][0].y);
				dp[j][l][0].i1 = il_1, dp[j][l][0].i2 = l;
//				cout << "from right: " << i << " now left " << j << " to " << l << " ans: " << ans << '\n';
			}
		}
	}

	cout << ans - 1;

	return 0;
}

