#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 3e5;
int a[N + 5];
vector<int> idx[N + 5];
signed main() {
	int n, T;
    cin >> n >> T;
    for (int i = 1; i <= n; i ++) 
        cin >> a[i], idx[a[i]].push_back(i);
    while (T --) {
        int opt;
        cin >> opt;
        if (opt == 1) {
            int l, r, c;
            cin >> l >> r >> c;
        }
    }
    return 0;
}
