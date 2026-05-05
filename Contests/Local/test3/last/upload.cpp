#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 30000, k = 1e10;
int th[N + 5], ls[N + 5];
signed main() {
	ls[0] = 1;
	int n, r;
    cin >> n >> r;
	for (int i = 1; i <= n + 1; i ++) {
		for (int j = 1; j <= i; j ++)
			th[j] = ls[j] + ls[j - 1], th[j] %= k;
        memcpy(ls, th, sizeof th);
    }
    printf("%010lld", th[r + 1]);
	return 0;
}