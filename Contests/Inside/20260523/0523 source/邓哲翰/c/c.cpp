#include <bits/stdc++.h>
using namespace std;

long long n, cnt = 0, a[200005];

int main(){
	freopen("c.in", "r", stdin);
	freopen("c.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++){
		cnt += a[i] / 3;
		a[i] %= 3;
		if (i < n && a[i + 1] + a[i] >= 3){
			cnt++;
			a[i + 1] -= (3 - a[i]);
			a[i] = 0;
		}
	}
	cout << cnt;
	return 0;
}
