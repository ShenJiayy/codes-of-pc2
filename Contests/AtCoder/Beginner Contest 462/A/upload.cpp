#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	string s, ans;
    cin >> s;
    for (char c : s)
        if (isdigit(c))
            ans += c;
    cout << ans;
    return 0;
}
