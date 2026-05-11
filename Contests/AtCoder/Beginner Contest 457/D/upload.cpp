#include <bits/stdc++.h>
using namespace std;
#define int32 signed
#define int __int128
const int N = 2e5;
int a[N + 5], n, k;
inline bool check(int mid) {
    // 我就直接让他变成全部都是mid
    // 我就看它需要多久
    int cnt = 0;
    for (int i = 1; i <= n; i ++)
        if (a[i] < mid)
            cnt += (mid - a[i]) / i + bool((mid - a[i]) % i);
    return cnt <= k;
}
void read(int &x) {
    string s;
    cin >> s;
    x = 0;
    for (int32 i = 0; i < s.size(); i ++)
        x = x * 10 + s[i] - '0';
}
void print(int x) {
    if (x >= 10) print(x / 10);
    cout << char(x % 10 + '0');
}
signed main() {
    read(n), read(k);
    for (int i = 1; i <= n; i ++)
        read(a[i]);
    int l = 0, r = 5e18, ans;
    while (l <= r) {
        int mid = l + r >> 1;
        if (check(mid)) ans = mid, l = mid + 1;
        else r = mid - 1;
    }
    print(ans);
    return 0;
}