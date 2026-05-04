#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 31;
int pw2[N + 5];
signed main() {
    int n, k;
    cin >> n >> k;
    for (int i = 1, pw = 1; i <= N; i ++, pw *= 2)
        pw2[i] = pw2[i - 1] + pw;
    unordered_map<int, bool> mp;
    int cnt = 0;
    while (n) {
        if (mp[n]) {
            cout << "ERROR";
            return 0;
        } 
        mp[n] = 1;
        int id = upper_bound(pw2 + 1, pw2 + N + 1, n) - pw2 - 1;
        n -= pw2[id], cnt += id;
        if (n != 0)
            n += k;
    }
    cout << "OK " << cnt;
    return 0;
}