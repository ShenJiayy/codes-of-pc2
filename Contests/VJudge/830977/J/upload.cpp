#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1002;
int p, q, n;
struct Node {
	double x, y;
} a[N + 5];
struct Edge {
	int x, y;
	double dis;
} dist[N * N + 5];
bool cmp(Edge x, Edge y) {
	return x.dis < y.dis;
}
int f[N + 5];
void init(int n) {
	for (int i = 1; i <= n; i ++)
		f[i] = i;
}
int find(int id) {
	if (f[id] != id)
		f[id] = find(f[id]);
	return f[id];
}
void merge(int x, int y) {
	int ftx = find(x), fty = find(y);
	if (ftx != fty)
		f[ftx] = fty;
}
signed main() {
	cin >> p >> q >> n;
	for (int i = 1; i <= n; i ++)
		cin >> a[i].x >> a[i].y;
	a[n + 1] = {0, double(p)}, a[n + 2] = {double(q), 0};
	int curr = 0;
	for (int i = 1; i <= n + 2; i ++)
		for (int j = i + 1; j <= n + 2; j ++)
			dist[++ curr] = {i, j, (a[i].x - a[j].x) * (a[i].x - a[j].x) + (a[i].y - a[j].y) * (a[i].y - a[j].y)};
	sort(dist + 1, dist + curr + 1, cmp);
	double l = 0, r = 15e5, ans;
	while (r - l >= 1e-6) {
		init(n + 2);
		double mid = (l + r) / 2;
		for (int i = 1; i <= curr; i ++)
			if (dist[i].dis <= mid * mid)
				merge(dist[i].x, dist[i].y);
		if (find(n + 1) == find(n + 2)) // Fake Answer
			r = mid - 1;
		else ans = mid, l = mid + 1;
	}
	cout << ans;
	return 0;
}