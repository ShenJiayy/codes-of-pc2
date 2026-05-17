#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int n;
    string s;
    cin >> s >> n;
    string res;
    for (int i = n; i < s.size() - n; i ++)
        res += s[i];
    cout << res;
    return 0;
}
