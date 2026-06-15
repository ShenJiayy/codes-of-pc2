#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 100;
vector<int> g[N + 5];
signed main() {
	int n;
    cin >> n;
    for (int i = 1; i <= n; i ++) {
        int k;
        cin >> k;
        while (k --) {
            int x;
            cin >> x;
            g[x].push_back(i);
        }
    }
    for (int i = 1; i <= n; i ++) 
        sort(g[i].begin(), g[i].end());
    for (int i = 1; i <= n; i ++) {
        cout << g[i].size() << " ";
        for (int v : g[i])
            cout << v << " ";
        cout << endl;
    }
    return 0;
}
