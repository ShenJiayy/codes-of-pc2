#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5;
int a[N + 5];
signed main() {
	int n;
    cin >> n;
    map<int, int> mp;
    for (int i = 1; i <= n; i ++) 
        cin >> a[i], mp[a[i]] = i;
    for (int i = 1; i <= n; i ++) {
        int nxt = mp[a[i]];
        for (int j = i; j < nxt; j ++)
            a[j] = a[i];
        i = nxt;
    }
    for (int i = 1; i <= n; i ++)
        cout << a[i] << endl;
	return 0;
}
