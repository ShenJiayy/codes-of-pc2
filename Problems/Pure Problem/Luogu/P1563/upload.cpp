#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5;
bool in[N + 5];
string name[N + 5];
signed main() {
	int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
        cin >> in[i] >> name[i];
    int p = 1;
    while (m --) {
        int x, y;
        cin >> x >> y;
        if (in[p] && x || !in[p] && !x) p -= y;
        else p += y;
        if (p > n) p -= n;
        if (p <= 0) p += n;
        // cout << p;
    }
    cout << name[p];
    return 0;
}