#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1000;
struct Per {
    int val, idx;
} a[N + 5];
int s[N + 5];
bool cmp(Per x, Per y) {
    if (x.val != y.val) return x.val < y.val;
    return x.idx < y.idx;
}
signed main() {
	int n;
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i].val, a[i].idx = i;
    sort(a + 1, a + n + 1, cmp);
    for (int i = 1; i <= n; i ++)
        printf("%lld ", a[i].idx);
    printf("\n");
    double avg = 0;
    for (int i = 1; i <= n; i ++) {
        s[i] = s[i - 1] + a[i].val;
        avg += s[i - 1];
    }
    avg /= n;
    printf("%.2lf", avg);
    return 0;
}
