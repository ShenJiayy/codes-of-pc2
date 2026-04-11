#include <bits/stdc++.h>
using namespace std;
#define int long long
const int S = 2e5, T = 50;
char s[S + 5], t[T + 5];
int dp[S + 5][T + 5];
signed main() {
    string ss, tt;
    cin >> ss >> tt;
    for (int i = 0; i < ss.size(); i ++)
        s[i + 1] = ss[i];
    for (int i = 0; i < tt.size(); i ++)
        t[i + 1] = tt[i];
    int slen = ss.size(), tlen = tt.size();
    cout << dp[slen][tlen];
    return 0;
}