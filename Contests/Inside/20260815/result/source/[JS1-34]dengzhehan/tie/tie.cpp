#include <bits/stdc++.h>
using namespace std;

int n, a[200005], b[200005];
bool x[200005];

int func_102_42_42_107_95_104_42_120(int idx){
	if (idx > n) return 0;
	int mn = 2147483647;
	for (int i = 1; i <= n + 1; i++){
		if (!x[i]){
			x[i] = 1;
			mn = min(mn, max(max(a[i] - b[idx], 0),
					 func_102_42_42_107_95_104_42_120(idx + 1)));
			x[i] = 0;
		}
	}
//	cout << idx << " # " << mn << endl;
	return mn;
}

int main(){
	freopen("tie.in", "r", stdin);
	freopen("tie.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n + 1; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> b[i];
	for (int k = 1; k <= n + 1; k++){
		x[k] = 1;
		cout << func_102_42_42_107_95_104_42_120(1) << ' ';
		x[k] = 0;
	}
	return 0;
}
