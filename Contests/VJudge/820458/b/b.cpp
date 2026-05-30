#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 4e5;
int a[N + 5];
signed main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n * 2 + 2; i ++)
		cin >> a[i];
	int m = n * 2 + 2, ans = 0;
	priority_queue<int> od;
	int curr = m;
	for (int i = 1; i <= n + 1; i ++) {
		od.push(a[curr --]);
		ans = max(ans, a[curr --] + od.top());
	}
	cout << ans;
	return 0;
} 