#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5;
vector<int> a[N + 5];
signed main() {
	int n;
    cin >> n;
    for (int i = 1; i <= n; i ++) {
        int l;
        cin >> l;
        a[i].resize(l + 1);
        for (int j = 1; j <= l; j ++)
            cin >> a[i][j];
    }
    int x, y;
    cin >> x >> y;
    cout << a[x][y];
    return 0;
}
