#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 3e4;
int f[N + 5], dist[N + 5], size[N + 5];
int find(int x) {
    if (f[x] == x) return x;
    int fn = find(f[x]);
    dist[x] += dist[f[x]];
    return f[x] = fn;
}
void merge(int x, int y) {
	int ftx = find(x), fty = find(y);
    dist[ftx] += size[fty];
    f[ftx] = fty;
    size[fty] += size[ftx];
    size[ftx] = 0;
}
int query(int x, int y) {
	int ftx = find(x), fty = find(y);
	if (ftx != fty) return -1;
	return abs(dist[x] - dist[y]) - 1;
}
signed main() {
	#ifndef ONLINE_JUDGE
		freopen("in.in", "r", stdin);
	#endif
	int q;
	cin >> q;
	for (int i = 1; i <= N; i ++)
		f[i] = i, size[i] = 1;
	while (q --) {
		char opt;
		int x, y;
		cin >> opt >> x >> y;
		if (opt == 'M')
			merge(x, y);
		else 
			cout << query(x, y) << endl;
	}
	return 0;
}
