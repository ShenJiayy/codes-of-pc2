#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5;
int a[N + 5];
signed main() {
	int T;
    cin >> T;
    while (T --) {
        int n;
        cin >> n;
        map<int, int> mp;
        for (int i = 1; i <= n; i ++)
            cin >> a[i], mp[a[i]] ++;
        map<int, int> rnk;
        int curr = 0;
        for (auto kv : mp)
            rnk[kv.first] = ++ curr;
        for (int i = 1; i <= n; i ++)
            cout << rnk[a[i]] << " ";
        cout << endl;
    }
    return 0;
}
