#include <iostream>
#include <algorithm>
#define int long long
#define FOR(i, st, ed) for (int i = st; i <= ed; i++)
#define ROF(i, st, ed) for (int i = st; i >= ed; i--)
using namespace std;

const int N = 2e5 + 5;
int n, a[N], b[N];
int x[N], maxx[N];
int y[N], maxy[N];

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("tie.in", "r", stdin);
	freopen("tie.out", "w", stdout);
	cin >> n;
	FOR(i, 1, n + 1) cin >> a[i];
	FOR(i, 1, n) cin >> b[i];
	sort(a + 1, a + n + 1);
	sort(b + 1, b + n + 1);
	FOR(i, 1, n) x[i] = max(a[i] - b[i], 0LL);
	FOR(i, 1, n) y[i] = max(a[i + 1] - b[i], 0LL);
	FOR(i, 1, n) maxx[i] = max(maxx[i - 1], x[i]);
	ROF(i, n, 1) maxy[i] = max(maxy[i + 1], y[i]);
	FOR(i, 1, n + 1) cout << max(maxx[i - 1], maxy[i]) << ' ';
	return 0;
}
