#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 3e5;
struct pos {
    int x, y;
} a[N + 5];
int s[N + 5];
int lowbit(int x) {
    return x & -x;
}
void update(int x, int d) {
    for (; x <= N; x += lowbit(x))
        s[x] += d;
}
int query(int x) {
    int ret = 0;
    for (; x; x -= lowbit(x))
        ret += s[x];
    return ret;
}
bool cmp(pos x, pos y) {
    if (x.x != y.x) return x.x < y.x;
    return x.y < y.y;
}
signed main() {
	int n;
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i].x >> a[i].y;
    int cnt = 0;
    sort(a + 1, a + n + 1, cmp);
    for (int i = 1; i <= n; i ++) {
        bool valid = 1;
        if (a[i].x != a[1].x) {
            int sum = query(a[i].y - 1);
            if (sum)
                valid = 0;
        }
        update(a[i].y, 1);
        cnt += valid;
    }
    cout << cnt;
    return 0;
}
