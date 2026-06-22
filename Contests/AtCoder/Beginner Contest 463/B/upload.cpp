#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 100;
char s[N + 5][128];
signed main() {
	int n;
    char x;
    cin >> n >> x;
    for (int i = 1; i <= n; i ++)
        for (int j = 'A'; j <= 'E'; j ++)
            cin >> s[i][j];
    bool valid = 0;
    for (int i = 1; i <= n; i ++)
        valid |= s[i][x] == 'o';
    cout << (valid?"Yes":"No");
    return 0;
}
