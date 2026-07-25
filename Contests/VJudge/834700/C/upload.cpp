#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	set<int> s;
	int n, T;
	cin >> n >> T;
	for (int i = 1; i <= n; i ++) {
		int x;
		cin >> x;
		s.insert(x);
		s.insert(x + 1);
	}
	
	return 0;
} 
