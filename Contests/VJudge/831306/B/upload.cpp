#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e4;
struct Node {
	int l, r, id;
} a[N + 5];
bool operator < (Node x, Node y) {
	return x.l < y.l;
}
bool operator > (Node x, Node y) {
	return x.l > y.l;
}
int ans[N + 5];
signed main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i ++)
		cin >> a[i].l >> a[i].r, a[i].id = i;
	sort(a + 1, a + n + 1);
	priority_queue<Node, deque<Node>, greater<Node>> q;
	int idx = 2;
	q.push({a[1].r, 0, a[1].id});
	ans[a[1].id] = 1;
	for (int i = 2; i <= n; i ++) {
		if (a[i].l > q.top().l) {
			ans[a[i].id] = ans[q.top().id];
			q.pop();
		}
		else 
			ans[a[i].id] = idx ++;
		q.push({a[i].r, 0, a[i].id});
	}
	cout << idx - 1 << endl;
	for (int i = 1; i <= n; i ++)
		cout << ans[i] << endl;
	return 0;
}