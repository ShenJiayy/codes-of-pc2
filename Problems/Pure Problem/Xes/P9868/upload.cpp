#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 3000;
string w[N + 5][3];
signed main() {
	int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
        cin >> w[i][0];
    for (int i = 1; i <= n; i ++) {
        w[i][2] = w[i][1] = w[i][0];
        sort(w[i][1].begin(), w[i][1].end());
        sort(w[i][2].begin(), w[i][2].end(), greater<char>());
    }
    for (int i = 1; i <= n; i ++) {
        bool valid = 1;
        for (int j = 1; j <= n; j ++)
            if (j != i && w[i][1] >= w[j][2])
                valid = 0;
        cout << valid;
    }
    return 0;
}
