#include <bits/stdc++.h>
using namespace std;
#define int long long
const int M = 1e7 + 5;
bool valid[M + 5];
int validnum[M + 5], curr, mp[M + 5];
bool check(int x) {
	if (x % 7 == 0) return 0;
	while (x) {
		if (x % 10 == 7) return 0;
		x /= 10;
	}
	return 1;
}
signed main() {
	int T;
	cin >> T;
	memset(valid, 1, sizeof valid);
	for (int i = 1; i <= M + 5; i ++)
		if (valid[i] && !check(i))
			for (int j = i; j <= M + 5; j += i)
				valid[j] = 0;
	for (int i = 1; i <= M + 5; i ++)
		if (valid[i])
			validnum[++ curr] = i, mp[i] = curr;
	while (T --) {
		int x;
		cin >> x;
		if (valid[x] == 0) {
			puts("-1");
			continue;
		}
		cout << validnum[mp[x] + 1] << endl;
	}
	return 0;
}