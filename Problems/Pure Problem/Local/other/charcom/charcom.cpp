// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// char s[30];
// int getc(int n, int m) {
//     if (m > n || m < 0) return 0;
//     if (m == 0 || m == n) return 1;
//     if (m > n - m) m = n - m;
//     int res = 1.0;
//     for (int i = 1; i <= m; i ++)
//         res = res * (n - m + i) / i;
//     return res;
// }
// signed main() {
// 	// Code here.
//     int n;
//     cin >> n >> s + 1;
//     int len = strlen(s + 1), ans = 0;
//     for (int i = 1; i < s[1] - 'A' + 1; i ++) 
//         for (int j = 1; j <= n - i; j ++)
//             ans += getc(n - i, j);
//     int lst = s[1] - 'A' + 1;
//     for (int i = 2; i <= len; i ++) {
//         int curr = s[i] - 'A' + 1;
//         for (int j = lst + 1; j < curr; j ++) {
//             int canuse = n - j;
//             int lost = len - i;
//             ans += getc(canuse, lost);
//         }
//         lst = curr;
//     }
//     cout << ans + 1;
//     return 0;
// }