#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 100000;
int a[N + 5], s[N + 5], sp[N + 5][2];
signed main() {
	while (1) {
		int c, n;
		cin >> c >> n;
		if (c == n && n == 0) return 0;
		for (int i = 1; i <= n; i ++)
			cin >> a[i];
		for (int i = 1; i <= n; i ++)
			s[i] = s[i - 1] + a[i];
		for (int i = 1; i <= n; i ++) {
			int p = s[i] % n;
			if (!sp[p][0]) sp[p][0] = i;
			else if (!sp[p][1]) sp[p][1] = i;
		}
		int ans = -1;
		for (int i = 0; i < n; i ++)
			if (sp[i][1]) {
				ans = i;
				break;
			}
		if (ans == -1) 
			cout << "no sweets";
		else
			for (int i = sp[ans][0]; i <= sp[ans][1]; i ++)
				cout << i << " ";
		cout << endl;
	}
	return 0;
}
