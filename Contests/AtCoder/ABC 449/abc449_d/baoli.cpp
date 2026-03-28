#include <bits/stdc++.h>
using namespace std;
int main() {
	int l, r, d, u;
	cin >> l >> r >> d >> u;
	int ans = 0;
	for (int i = l; i <= r; i ++)
		for (int j = d; j <= u;  j ++)
			if (!(max(abs(i), abs(j)) & 1))
				ans ++;
	cout << ans;
}
