#include <bits/stdc++.h>
using namespace std;
#define int long long
#define gcd(x, y) __gcd(x, y)
#define lcm(x, y) (x / gcd(x, y) * y)
const int N = 20;
int a[N + 5];
signed main() {
	int n;
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i], a[i] = abs(a[i]);
    int S = a[1];
    for (int i = 2; i <= n; i ++)
        S = gcd(S, a[i]);
    cout << S;
    return 0;
}