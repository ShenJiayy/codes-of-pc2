#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5;
int l[N + 5], r[N + 5], n;
int query(int id) {
	int lid = lower_bound(l + 1, l + n + 1, id) - l - 1;
	int rid = lower_bound(r + 1, r + n + 1, id) - r - 1;
	return lid - rid;
}
signed main() {
	int T;
	cin >> n >> T;
	for (int i = 1; i <= n; i ++)
		cin >> l[i] >> r[i];
	sort(l + 1, l + n + 1);
	sort(r + 1, r + n + 1);
	unordered_map<int, bool> flg;
	int ans = n;
	while (T --) {
		int ql, qr;
		cin >> ql >> qr;
		if (!flg[ql]) {
			flg[ql] = 1;
			ans += query(ql);
		}
		if (!flg[qr + 1]) {
			flg[qr + 1] = 1;
			ans += query(qr + 1);
		}
		cout << ans << endl;
	}
	return 0;
}
