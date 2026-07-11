#include <iostream>
using namespace std;
typedef long long ll;
int C(int n, int m) {}
int main() {
	ll n;
	cin >> n;
	if (n == 1) {
		puts("1");
		return 0;
	}
	for (ll i = 16; i >= 2; i--) {
		for (ll j = (i<<1); true; j++) {
			ll k = C(j, i);
			if (k == n) {
				cout << j * (j+1) / 2 + i + 1;
				return 0;
			} 
            else if (k > n) 
                break;
		}
	}
	cout << n * (n + 1) / 2 + 2;
	return 0;
}
