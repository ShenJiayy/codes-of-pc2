#include <bits/stdc++.h>
using namespace std;
#define int long long
struct MaxRMQ {
    int f[100005][30];
    MaxRMQ() {
        memset(f, -0x3f, sizeof f);
    }
    void init(int n, int a[], bool opt = 0) {
        for (int i = 1; i <= n; i ++)
            if (opt == 0 || a[i] < 0)
                f[0][i] = a[i];
        for (int i = 1; (1 << i) <= n; i ++)
            for (int j = 1; j <= n - (1 << i) + 1; j ++)
                f[i][j] = max(f[i - 1][j], f[i - 1][j + (1 << i - 1)]);
    }
    int query(int l, int r) {
        int sz = log2(r - l + 1);
        return max(f[sz][l], f[sz][r - (1 << sz) + 1]);
    }
} AMax, DnAMax, BMax;
struct MinRMQ {
    int f[100005][30];
    MinRMQ() {
        memset(f, 0x3f, sizeof f);
    }
    void init(int n, int a[], bool opt = 0) {
        for (int i = 1; i <= n; i ++)
            if (opt == 0 || a[i] >= 0)
                f[0][i] = a[i];
        for (int i = 1; (1 << i) <= n; i ++)
            for (int j = 1; j <= n - (1 << i) + 1; j ++)
                f[i][j] = min(f[i - 1][j], f[i - 1][j + (1 << i - 1)]);
    }
    int query(int l, int r) {
        int sz = log2(r - l + 1);
        return min(f[sz][l], f[sz][r - (1 << sz) + 1]);
    }
} AMin, UpAMin, BMin;
const int N = 1e5;
int a[N + 5], b[N + 5];
bool valid(int x) {
    return -4557430888798830399 <= x && x <= 4557430888798830399;
}
signed main() {
	/*
小Q的策略为如下情况：
- L选正：Q选最小
- L选负：Q选最大
小L的策略如下：
- L选正数最小
- L选正数最大
- L选负数最小
- L选负数最大
    */
    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    for (int i = 1; i <= m; i ++)
        cin >> b[i];
    AMax.init(n, a);
    AMin.init(n, a);
    DnAMax.init(n, a, 1);
    UpAMin.init(n, a, 1);
    BMax.init(m, b);
    BMin.init(m, b);
    while (q --) {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        int ans = -9e18;
        int amx = AMax.query(l1, r1);
        int amn = AMin.query(l1, r1);
        int aumn = UpAMin.query(l1, r1);
        int admx = DnAMax.query(l1, r1);
        int bmx = BMax.query(l2, r2);
        int bmn = BMin.query(l2, r2);
        ans = max(ans, amx * (amx >= 0 ? bmn : bmx));
        ans = max(ans, amn * (amn >= 0 ? bmn : bmx));
        if (valid(aumn))
            ans = max(ans, aumn * (aumn >= 0 ? bmn : bmx));
        if (valid(admx))
            ans = max(ans, admx * (admx >= 0 ? bmn : bmx));
        cout << ans << endl;
    }
    return 0;
}
