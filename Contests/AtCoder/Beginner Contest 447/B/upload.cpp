#include <bits/stdc++.h>
using namespace std;
#define int long long
#define local
int box[128];
bool flag[128];
signed main() {
    #ifdef local
        freopen("in.in", "r", stdin);
    #endif
    string s;
    cin >> s;
    for (char c : s)
        box[c] ++;
    int maxn = *max_element(box + 'a', box + 'z' + 1);
    for (int i = 0; i <= 127; i ++)
        if (box[i] == maxn)
            flag[i] = 1;
    string ans = "";
    for (char c : s)
        if (flag[c] == 0)
            ans += c;
    cout << ans;
    return 0;
}