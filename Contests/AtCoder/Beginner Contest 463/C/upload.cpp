#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 3e5;
int maxn[N + 5], n, l[N + 5];
struct Takashi {
    int h, l;
    Takashi() {h = l = 0;}
} a[N + 5];
bool cmp(Takashi x, Takashi y) {
    return x.l < y.l;
}
int getans(int p) {
    if (p == -1) p = 1;
    return maxn[p]; 
}
signed main() {
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i].h >> a[i].l;
    sort(a + 1, a + n + 1, cmp);
    // 越在前面走得越早
    for (int i = n; i >= 1; i --)
        maxn[i] = max(maxn[i + 1], a[i].h), l[i] = a[i].l;
    int T;
    cin >> T;
    while (T --) {
        int p;
        cin >> p;
        cout << getans(upper_bound(l + 1, l + n + 1, p) - l) << endl;
    }
    return 0;
}
