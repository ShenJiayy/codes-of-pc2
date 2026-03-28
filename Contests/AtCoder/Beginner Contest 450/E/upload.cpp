#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e7;
string s[N + 5];
signed main() {
    int n;
    cin >> n >> s[1] >> s[2];
    for (int i = 3; i <= n; i ++)
        s[i] = s[i - 1] + s[i - 2];
    for (int i = 1; i <= n; i ++)
        cout << i << ": " << s[i] << endl;
    return 0;
}