#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	unordered_map<string, bool> mp;
	for (int i = 1; i <= n; i ++) {
		string s;
		cin >> s;
		mp[s] = 1;
	}
	cout << mp.size();
	return 0;
}