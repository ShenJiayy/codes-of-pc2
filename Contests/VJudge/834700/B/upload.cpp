#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	int n;
	cin >> n;
	priority_queue<int> q1; int c1 = 0;
	priority_queue<int, deque<int>, greater<int>> q2; int c2 = 0;
	for (int i = 1; i <= n; i ++) {
		int x;
		cin >> x;
		q1.push(x);
		c1 ++;
	}
	while (c1 > n / 2) {
		q2.push(q1.top()); c2 ++;
		q1.pop(); c1 --;
	}
	int T;
	cin >> T;
	while (T --) {
		string opt;
		cin >> opt;
		if (opt == "add") {
			int a;
			cin >> a;
			n ++;
			if (a > q1.top()) q2.push(a), c2 ++;
			else q1.push(a), c1 ++;
		}
		else {
			while (c1 > (n + 1) / 2) {
				q2.push(q1.top()); c2 ++;
				q1.pop(); c1 --;
			}
			while (c1 < (n + 1) / 2) {
				q1.push(q2.top()); c1 ++;
				q2.pop(); c2 --;
			}
			cout << q1.top() << endl;
		}
	}
	return 0;
} 
