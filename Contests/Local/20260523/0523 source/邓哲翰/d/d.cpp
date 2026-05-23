#include <bits/stdc++.h>
using namespace std;

int n, q, a[300005];

int main(){
	freopen("d.in", "r", stdin);
	freopen("d.out", "w", stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> a[i];
	int c, d;
	for (int i = 1; i <= q; i++){
		cin >> c >> d;
		long long min = 1152921504606846976;
		for (int j = 0; ; j++){
			long long sum = c * j;
			for (int k = 1; k <= n; k++){
				sum += max(0, a[k] - d * j);
			}
			if (sum < min){
				min = sum;
			}else{
				break;
			}
		}
		cout << min << '\n';
	}
	return 0;
}
