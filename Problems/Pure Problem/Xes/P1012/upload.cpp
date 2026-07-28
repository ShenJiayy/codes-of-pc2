#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 20;
int a[N + 5];
bool cmp(int x, int y) {
    // 返回值为1 x在前
    return stoll(to_string(x) + to_string(y)) > stoll(to_string(y) + to_string(x));
}
signed main() {
	int n;
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    sort(a + 1, a + n + 1, cmp);
    for (int i = 1; i <= n; i ++)
        cout << a[i];
    return 0;
}