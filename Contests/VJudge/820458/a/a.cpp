#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	map<int, int> mp;
	int n;
	cin >> n;
	for (int i = 1; i <= n; i ++) {
		int x;
		cin >> x;
		mp[x] ++;
	}
	for (auto kv : mp)
		if (mp.count(kv.first + 3) && mp.count(kv.first + 6)) {
			cout << "Yes";
			return 0;
		}
	cout << "No";
	return 0;
} 