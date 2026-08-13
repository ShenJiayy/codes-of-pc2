#include <bits/stdc++.h>
using namespace std;

int n, a[500005];

bool cmp(int a, int b){
	return a > b;
}

int l_t(int x){
	for (int i = x; i >= 1; i--){
		if (a[x] != a[i]){
			return i + 1;
		}
	}
	return 1;
}

int l_w(int x){
	for (int i = x; i <= n; i++){
		if (a[x] != a[i]){
			return i - 1;
		}
	}
	return n;
}

int main(){
	freopen("b.in", "r", stdin);
	freopen("b.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1, cmp);
	int m = n / 2;
	int v1 = l_w(m);
	int v2 = abs(v1 - (n - v1));
	int v3 = l_t(m);
	int v4 = m;
	if (v3 > 1){
		int v5 = abs((v3 - 1) - (n - (v3 - 1)));
		if (v5 <= v2){
			v2 = v5;
			v4 = v3 - 1;
		}
	}
//	printf("# %d %d %d %d\n", v1, v2, v3, v4);
	if (v1 < n){
		int v6 = l_w(v1 + 1);
		int v5 = abs(v6 - (n - v6));
		if (v5 < v2){
			v4 = v1 + 1;
		}
	}
	cout << a[l_w(v4)];
	return 0;
}
