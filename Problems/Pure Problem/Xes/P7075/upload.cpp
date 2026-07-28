#include <bits/stdc++.h>
using namespace std;
#define int long long
bool check(int y) {
    if (y > 1582)
        return (y % 4 == 0) && (y % 100 != 0) || (y % 400 == 0);
    if (y > 0)
        return (y % 4 == 0);
    return y % 4 == -1; 
}
int yday(int y) {
    if (y == 1582)
        return 355;
    return 365 + check(y);
} 
const int md[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int mday(int m, int y) {
    if (y == 1582 && m == 10)
        return md[m] - 10;
    if (m == 2)
        return md[m] + check(y);
    return md[m];
}
void solve(int r) {
    r ++;
    int y = -4713;
    while (r >= yday(y)) {
        r -= yday(y);
        y ++;
        if (y == 0) y ++;
    }
    int m = 1;
    while (r >= mday(m, y)) 
        r -= mday(m, y), m ++;
    int d = r;
    if (d == 0) d = md[m - 1], m --;
    if (m == 0) m = 12, y --;
    if (y == 0) y --;
    cout << d << " " << m << " " << abs(y) << " ";
    if (y < 0) cout << "BC";
    cout << endl;
}
signed main() {
	int T;
    cin >> T;
    while (T --) {
        int x;
        cin >> x;
        solve(x);
    }
    return 0;
}
