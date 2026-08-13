#include <bits/stdc++.h>
using namespace std;
#define int long long
 #define judge
const int N = 1e6;
string inp[N + 5];
inline char turn(char x, char y) {
    if (x == y) return x;
    if (x == 'a' && y == 'b') return 'c';
    if (x == 'b' && y == 'a') return 'c';
    if (x == 'a' && y == 'c')  return 'b';
    if (x == 'c' && y == 'a')  return 'b';
    return 'a';
}
string doit(string s) {
    if (s.size() == 1) return s;
    string ans;
    for (int i = 0; i + 1 < s.size(); i ++) 
        ans += turn(s[i], s[i + 1]);
    return ans;
}

signed main() {
    #ifdef judge
        freopen("abc.in", "r", stdin);
        freopen("abc.out", "w", stdout);
    #else
        freopen("data.in", "r", stdin);
        freopen("data.out", "w", stdout);
        freopen("data.log", "w", stderr);
    #endif
    int T;
    cin >> T;
    int ss = 0;
    for (int i = 1; i <= T; i ++)
        cin >> inp[i], ss += inp[i].size();
    if (ss <= 1e4)
        for (int i = 1; i <= T; i ++) {
            string s = inp[i];
            while (s.size() >= 2) s = doit(s);
            cout << s << endl;
        }
    else
        cout << "Only supported subtask 1.";
    return 0;
}
