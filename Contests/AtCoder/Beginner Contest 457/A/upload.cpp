#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 100;
int a[N + 5];
signed main() {
	int n;
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    int x;
    cin >> x;
    cout << a[x];
    return 0;
}
