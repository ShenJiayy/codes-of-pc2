#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5;
int d[N + 5], n;
signed main() {
    int sum = 0;
    cin >> n;
	for (int i = 1; i <= n; i ++)
        cin >> d[i];
    for (int i = 1; i <= n; i ++)
        if (d[i] > d[i - 1])
            sum += d[i] - d[i - 1];
    cout << sum;
    return 0;
}