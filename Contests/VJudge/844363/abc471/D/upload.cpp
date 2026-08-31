#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	int T, m;
	cin >> T >> m;
	priority_queue<int> q;
	int ft = 0;
	while (T --) {
		int opt, t;
		cin >> opt >> t;
		if (opt == 1) {
			int w;
			cin >> w;
			// append.
			q.push(w - t);
		}
		if (opt == 2) {
			if (q.empty()) {
				puts("-1");
				fflush(stdout);
				continue;
			}
			int tp = q.top() + t;
			if (tp > m)
				tp = m;
			cout << tp << endl;
			q.pop();
		}
	}
	return 0;
}