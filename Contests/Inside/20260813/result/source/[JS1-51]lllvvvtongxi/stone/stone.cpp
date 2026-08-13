#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int n, a[N], q[N], d[N];

struct Data {
	int id, val;
} p[N];

bool cmp (Data a, Data b) {
	return a.val < b.val;
}

int main () {
	
	freopen ("stone.in", "r", stdin);
	freopen ("stone.out", "w", stdout);

	cin >> n;
	for (int i = 1; i <= n; i ++) {
		cin >> d[i];
		p[i].id = i;
		p[i].val = d[i];
	}
	
	sort (p + 1, p + n + 1, cmp);
	
	for (int i = 1; i <= n; i ++) {
		a[p[i].id] = i;
		if (p[i].val == p[i - 1].val)
			a[p[i].id] = a[p[i - 1].id];
	}
	
	for (int i = 1; i <= n; i ++)
		q[a[i]] = i;
	
	for (int i = 1; i <= n; i ++) {
		for (int j = i; j <= q[a[i]]; j ++)
			cout << d[i] << "\n";
		i = q[a[i]];
	}
	
	return 0;
	
}
