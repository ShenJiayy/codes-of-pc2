#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int _;
    cin >> _;
    string s;
    cin >> s;
    int p = 0;
    for (; p < s.size(); p ++)
        if (s[p] != 'o')
            break;
    for (int i = p; i < s.size(); i ++)
        cout << s[i];
    return 0;
}