#include <bits/stdc++.h>
using namespace std;
#define int long long
int num[1000];
signed main() {
    string s;
    int k;
    cin >> s >> k;
    while (k --) {
        int p = 0;
        while (p < s.size() && s[p] <= s[p + 1]) p ++;
        s.erase(p, 1);
    }
    while (s.size() >= 2 && s[0] == '0') s.erase(0, 1);
    cout << s;
    return 0;
}