#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5;
struct RMQ {
    int f[N + 5][30];
    RMQ() {
        memset(f, -0x3f, sizeof f);
    }
    void init(int n, int a[], int (*opt)(int, int)) {
        for (int i = 1; i <= n; i ++)
            f[0][i] = a[i];
        for (int i = 1; (1 << i) <= n; i ++)
            for (int j = 1; j <= n - (1 << i) + 1; j ++)
                f[i][j] = opt(f[i - 1][j], f[i - 1][j + (1 << i - 1)]);
    }
    int query(int l, int r) {
        int sz = log2(r - l + 1);
        return max(f[sz][l], f[sz][r - (1 << sz) + 1]);
    }
} AMax, DnAMax, BMax, AMin, UpAMin, BMin;
int a[N + 5], b[N + 5];
bool valid(int x) {
    return -9e12 <= x && x <= 9e12;
}
int solve(int l1, int r1, int l2, int r2) {
    int ans = -9e18;
    int amx = AMax.query(l1, r1);
    int amn = AMin.query(l1, r1);
    int aumn = UpAMin.query(l1, r1);
    int admx = DnAMax.query(l1, r1);
    int bmx = BMax.query(l2, r2);
    int bmn = BMin.query(l2, r2);
    if (bmn >= 0) 
        return amx * ((amx > 0) ? bmn : bmx);
    if (bmx <= 0) 
        return amn * ((amn > 0) ? bmn : bmx);
    // max*=nmaxA.query(l1,r1),min*=pminA.query(l1,r1);
    // return min>0||max<=0&&max>min?max:min;
    int maxn = bmx * admx, minn = bmn * aumn;
    return (minn > 0 || maxn <= 0 && maxn > minn)?maxn:minn;    
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
    AMax.init(n, a, [](int a, int b){return a>b?a:b;});
    AMin.init(n, a, [](int a, int b){return a<b?a:b;});
    DnAMax.init(n, a, [](int a, int b){
        // if (a > b) swap(a, b);
        // if (a > 0) return (int)(-9e18);
        // if (b > 0) return a;
        // return b; 
        return (b >= 0 || a < 0 && a > b)?a:b;
    });
    UpAMin.init(n, a, [](int a, int b){
        // if (a < b) swap(a, b);
        // if (a < 0) return (int)(-9e18);
        // if (b < 0) return a;
        // return b; 
        return (b < 0 || a >= 0 && a < b)?a:b;
    });
    BMax.init(m, b, [](int a, int b){return a>b?a:b;});
    BMin.init(m, b, [](int a, int b){return a<b?a:b;});
    while (q --) {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        cout << solve(l1, r1, l2, r2) << endl;
    }
    return 0;
}