#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 3e5 + 5;
int n, q, a[N];
ll sum, p[N];

ll check (ll k, int c, int d) {
	if (! k) return sum;
	ll need = sum + 1ll * k * c;
	int l = 1, r = n, pos;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (a[mid] > 1ll * d * k) {
			pos = mid - 1;
			r = mid - 1;
		}
		else {
			pos = mid;
			l = mid + 1;
		}
	}
	need = need - p[pos] - 1ll * (n - pos) * k * d;
	return need;
}

int main () {
	
	freopen ("d.in", "r", stdin);
	freopen ("d.out", "w", stdout);
	
	cin >> n >> q;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
		sum += a[i];
	}
	
	if (n == 1) {
		while (q --) {
			int c, d;
			cin >> c >> d;
			if (c >= d) {
				cout << a[1] << endl;
				continue;
			}
			cout << min (a[1] - (d - c) * (a[1] / d), c * (a[1] / d + 1)) << endl;
		}
		return 0;
	}
		
	sort (a + 1, a + n + 1);
	
	for (int i = 1; i <= n; i ++) {
		p[i] = a[i] + p[i - 1];
	}	
		
	while (q --) {
		int c, d, k;
		cin >> c >> d;
		if (check (0, c, d) <= check (1, c, d)) {
			cout << sum << endl;
			continue;
		}
		int l = 1, r = 1e9;
		while (l < r) {
			int mid = (l + r) >> 1;
			int l_mid = (l + mid) >> 1;
			int r_mid = (r + mid) >> 1;
			ll _1 = check (l_mid, c, d), _2 = check (mid, c, d), _3 = check (r_mid, c, d);
			if (_1 >= _2 && _3 >= _2) {
				l = l_mid, r = r_mid;
				if (_2 == _3 || _2 == _1) {
					l = mid;
					break;
				}
				continue;
			}
			if (_1 < _2) {
				r = mid;
				continue;
			}
			if (_3 < _2) {
				l = mid;
				continue;
			}
		}
		cout << check ((l + r) >> 1, c, d) << endl;
	}
	
	return 0;
} 
