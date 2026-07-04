#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	string s;
    cin >> s;
    int e = 0, w = 0;
    for (char c : s)
        if (c == 'E') e ++;
        else w ++;
    if (e > w) cout << "East";
    else cout << "West";
    return 0;
}
