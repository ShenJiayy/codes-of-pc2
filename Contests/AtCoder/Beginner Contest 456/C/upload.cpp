#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 3e5, mod = 998244353;
char s[N + 5];
signed main() {
	scanf("%s", s + 1);
	int cnt = 0;
	int len = strlen(s + 1);
	int l = 1;
	for (int r = 1; r <= len; r ++) {
		if (s[r - 1] == s[r]) l = r;
		cnt += r - l + 1, cnt %= mod;
	}
	cout << cnt;
	return 0;
}
