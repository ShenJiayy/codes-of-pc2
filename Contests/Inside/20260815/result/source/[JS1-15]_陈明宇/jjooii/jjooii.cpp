#include <bits/stdc++.h>
#define ll long long

using namespace std;

string st, s;
bool flag;
ll n, k, ans = LLONG_MAX;

map<string, ll> id;

void dfs(string x, ll stp) {
	if (id.find(x) != id.end()) 
		if (stp > id[x]) return;
	id[x] = stp;
	if (x.size() < st.size()) return;
	if (x == st) {
		ans = min(ans, stp);
		flag = true;
		return;
	}
	string n1 = x, n2 = x, n3 = x;
	if (n1 != "") n1.erase(0, 1), dfs(n1, stp);
	if (n2 != "") n2.erase(n2.size() - 1, 1), dfs(n2, stp);
	if (n3 != "") {
		for (ll i = 1; i < n3.size() - 1; i++) {
			string nn = n3;
			nn.erase(i, 1);
			dfs(nn, stp + 1);
		}
	}
}

int main() {
	freopen("jjooii.in", "r", stdin);
	freopen("jjooii.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> k >> s;
	
	for (ll i = 1; i <= k; i++) st += 'J';
	for (ll i = 1; i <= k; i++) st += 'O';
	for (ll i = 1; i <= k; i++) st += 'I';

	dfs(s, 0);
	
	if (flag) cout << ans;
	else cout << -1;

	return 0;
}


