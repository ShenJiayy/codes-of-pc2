#include <bits/stdc++.h>
#define ll int

using namespace std;

class P {
public: ll x, y;
};

ll t, n, a[1000010];
P pos[200010];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	freopen("palin.in", "r", stdin);
	freopen("palin.out", "w", stdout);

	cin >> t;
	
	while (t--) {
		cin >> n;
		for (ll i = 1; i <= n; i++) pos[i] = {0, 0};
		
		for (ll i = 1; i <= 2 * n; i++) {
			cin >> a[i];
			if (pos[a[i]].x != 0) pos[a[i]].y = i;
			else pos[a[i]].x = i;
		}
		ll l = 1, r = 2 * n, cnt = 2, bl = pos[a[1]].y, br = bl;
		string ansl = "L", ansll = "L", ansr = "R", ansrr = "L";
		l++;
		bool flagl = false;
		while (cnt < 2 * n) {
			bool found = false;
			if (!found && l < bl) {
				ll nxt = pos[a[l]].y;
				if (nxt == bl - 1) {
					ansl += 'L', ansll += 'L';
					bl--, l++;
					found = true;
					cnt += 2;
				} else if (nxt == br + 1) {
					ansl += 'L', ansll += 'R';
					br++, l++;
					found = true;
					cnt += 2;
				}
			}
			if (!found && r > br) {
				ll pre = pos[a[r]].x;
				if (pre == bl - 1) {
					ansl += 'R', ansll += 'L';
					bl--, r--;
					found = true;
					cnt += 2;
				} else if (pre == br + 1) {
					ansl += 'R', ansll += 'R';
					br++, r--;
					found = true;
					cnt += 2;
				}
			}
			if (!found) {
				flagl = true;
				break;
			}
		}
		
		bool flagr = false;
		
		l = 1, r = n * 2, cnt = 2, bl = pos[a[2 * n]].x, br = bl;
		r--;
		while (cnt < 2 * n) {
			bool found = false;
			if (!found && l < bl) {
				ll nxt = pos[a[l]].y;
				if (nxt == bl - 1) {
					ansr += 'L', ansrr += 'L';
					bl--, l++;
					found = true;
					cnt += 2;
				} else if (nxt == br + 1) {
					ansr += 'L', ansrr += 'R';
					br++, l++;
					found = true;
					cnt += 2;
				}
			}
			if (!found && r > br) {
				ll pre = pos[a[r]].x;
				if (pre == bl - 1) {
					ansr += 'R', ansrr += 'L';
					bl--, r--;
					found = true;
					cnt += 2;
				} else if (pre == br + 1) {
					ansr += 'R', ansrr += 'R';
					br++, r--;
					found = true;
					cnt += 2;
				}
			}
			if (!found) {
				flagr = true;
				break;
			}
		}
		
		if (flagl && flagr) cout << "-1\n";
		else if (flagr || ((!flagl) && (!flagr))) {
			cout << ansl;
			reverse(ansll.begin(), ansll.end());
			cout << ansll << '\n';
		} else {
			cout << ansr;
			reverse(ansrr.begin(), ansrr.end());
			cout << ansrr << '\n';
		}
	}

	return 0;
}


