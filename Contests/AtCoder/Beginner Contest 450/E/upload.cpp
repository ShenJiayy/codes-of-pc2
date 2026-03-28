#include <bits/stdc++.h>
using namespace std;
#define int long long
int len[100], res[100][128];
string s[3];
int calc(int k, int x, char c) {
	if (k <= 2) {
		if (len[k] == x) {
			if (res[k][c] == -1) {
				res[k][c] = 0;
				for (int i = 0; i < x; i ++)
					if (s[k][i] == c) 
						res[k][c] ++;
			}
			return res[k][c];
		}
		int ans = 0;
		for (int i = 0; i < x; i ++)
			if (s[k][i] == c) 
				ans ++;
		return ans;
	}
	if (x <= len[k - 1])
		return calc(k - 1, x, c);
	else {
		if (res[k - 1][c] == -1)
			res[k - 1][c] = calc(k - 1, len[k - 1], c);
		return res[k - 1][c] + calc(k - 2, x - len[k - 1], c);
	}
}
signed main() {
	memset(res, -1, sizeof res);
    cin >> s[1] >> s[2];
    int q;
	cin >> q;
	len[1] = s[1].size();
	len[2] = s[2].size();
	int lst = 3;
	while (1) {
		len[lst] = len[lst - 1] + len[lst - 2]; 
		if (len[lst] > 1e18) break;
		lst ++;
	}
	while (q --) {
		int l, r;
		cin >> l >> r;
		char c;
		cin >> c;
		cout << calc(lst, r, c) - calc(lst, l - 1, c) << endl;
	}
    return 0;
}
