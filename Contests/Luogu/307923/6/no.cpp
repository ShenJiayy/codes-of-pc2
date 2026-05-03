#include<bits/stdc++.h>
using namespace std;
#define int long long
int n, a[600005], lc, rb; vector<int>v[1005];
inline vector<int>::iterator at(int p) {
	int ns = 0;
	for (int i = 0;; ++i)
		if (ns + v[i].size() < p) ns += v[i].size();
		else return v[i].begin() + (p - ns - 1);
}
inline int av(int p) {
	int ns = 0;
	for (int i = 0;; ++i)
		if (ns + v[i].size() < p) ns += v[i].size();
		else return i;
}
signed main() {
	ios::sync_with_stdio(0); cin >> n;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	rb = sqrt(n);
	for (int i = 1; i <= n; ++i) v[i / rb].emplace_back(a[i]);
	for (int i = 1, o, l, r; i <= n; ++i)
		if (cin >> o >> l, o & 1) cout << *at(l) << endl;
		else {
			cin >> r, v[av(l)].emplace(at(l), r); lc++;
			if (lc == 10 * rb) {
				lc = 0;
				for (int i = 0; v[i].size(); ++i)
					for (int j : v[i]) a[++lc] = j;
				for (int i = 0; v[i].size(); ++i) v[i].clear();
				rb = sqrt(lc);
				for (int i = 1; i <= lc; ++i) v[i / rb].emplace_back(a[i]);
				lc = 0;
			}
		}
}
