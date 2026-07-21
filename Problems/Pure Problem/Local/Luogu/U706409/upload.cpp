#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	string s;
    int n, ans;
    cin >> s >> n;
    ans = 0;
    for (int i = 0, j = s.size() - 1; i < s.size(); i ++, j --)
        if (s[j] == '1')
            ans |= 1ll << i;
    for (int i = 0, j = s.size() - 1; i < s.size(); i ++, j --)
        if (s[i] == '?' && (ans | 1ll << j) <= n)
            ans |= 1ll << j;
    if (ans > n) puts("-1");
    else cout << ans;
    return 0;
}