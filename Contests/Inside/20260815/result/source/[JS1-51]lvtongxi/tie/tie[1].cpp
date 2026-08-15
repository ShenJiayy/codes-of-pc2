#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int n, b[N], p[N], q[N];

struct Tie {
	int id, val;
} a[N];

bool cmp (Tie a, Tie b) {
	return a.val < b.val;
}

int ans[N];

int main () {
	
	freopen ("tie.in", "r", stdin);
	freopen ("tie.out", "w", stdout);

	cin >> n;
	for (int i = 1; i <= n + 1; i ++) {
		a[i].id = i;
		cin >> a[i].val;
	}
	for (int i = 1; i <= n; i ++) cin >> b[i];
	
	sort (a + 1, a + n + 1 + 1, cmp);
	sort (b + 1, b + n + 1);
	
	for (int i = 2; i <= n + 1; i ++)
		p[i] = max (0, a[i].val - b[i - 1]);
	for (int i = n + 1; i > 0; i --)
		p[i] = max (p[i], p[i + 1]);
	for (int i = 1; i <= n; i ++)
		q[i] = max (0, a[i].val - b[i]);
	for (int i = 1; i <= n; i ++)
		q[i] = max (q[i], q[i - 1]);
	
	for (int i = 1; i <= n + 1; i ++)
		ans[a[i].id] = max (q[i - 1], p[i + 1]);
		
	for (int i = 1; i <= n + 1; i ++)
		cout << ans[i] << " ";
	
	return 0;
}
