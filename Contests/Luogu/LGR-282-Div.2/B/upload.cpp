#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	deque<pair<int, int>> elm;
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i ++) {
		int l, r;
		cin >> l >> r;
		elm.push_back({l, r});
	}
	while (q --) {
		int opl, opr;
		cin >> opl >> opr;
		deque<pair<int, int>> now;
		for (auto pem : elm) {
			int l1 = max(pem.first, opl), r1 = min(pem.second, opr);
			if (l1 > r1) {
				now.push_back(pem);
				continue;
			}
			now.push_back({l1, r1});
			if (pem.first < l1)
				now.push_back({pem.first, l1 - 1});
			if (r1 < pem.second)
				now.push_back({r1 + 1, pem.second});
		}
		cout << now.size() << endl;
		elm = now;
	}
	return 0;
}
