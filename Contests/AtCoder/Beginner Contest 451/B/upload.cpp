#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 100;
int firstTerm[N + 5], secondTerm[N + 5];
signed main() {
	int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) {
        int a, b;
        cin >> a >> b;
        firstTerm[a] ++, secondTerm[b] ++;
    }
    for (int i = 1; i <= m; i ++) 
        cout << secondTerm[i] - firstTerm[i] << endl;
    return 0;
}