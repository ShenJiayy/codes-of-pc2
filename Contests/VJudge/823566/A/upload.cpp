#include <bits/stdc++.h>
using namespace std;
#define int long long
int len(int x) {
    if (x == 0) return 1;
    int cnt = 0;
    for (; x; x /= 10) cnt ++;
    return cnt;
}
struct frac {
    int p, q, r;
    frac() { p = 1, q = r = 0; }
    void hj() {
        int g = __gcd(p, q);
        p /= g, q /= g;
    }
    void tongfen(int x) {
        int lcm = p / __gcd(p, x) * x;
        lcm /= p;
        p *= lcm, q *= lcm;
    }
    void operator = (frac x) {
        p = x.p, q = x.q, r = x.r;
    }
    void jia() {
        q += p * r, r = 0;
    }
    void dai() {
        r += q / p, q %= p;
    }
    void printfrac() {
        cout << q << endl;
        int spx = len(p);
        while (spx --) 
            cout << "-";
        cout << endl << p;
    }
    void printall() {
        int spx = len(r);
        while (spx --)
			cout << " ";
        cout << q << endl << r;
        spx = len(p);
        while (spx --)
			cout << "-";
        cout << endl;
        spx = len(r);
        while (spx --)
			cout << " ";
        cout << p;
    }
    void print() {
        dai(), hj();
        if (p == 1 && q == 0) {
            cout << r;
            return ;
        }
        if (r)
            printall();
        else
            printfrac();
    }
};
frac operator + (frac x, frac y) {
    x.dai(), y.dai();
    int xp = x.p, yp = y.p;
    x.tongfen(yp), y.tongfen(xp);
    frac ans;
    ans.r = x.r + y.r;
    ans.p = x.p;
    ans.q = x.q + y.q;
    ans.hj();
    return ans;
}
frac operator * (frac x, frac y) {
    x.jia(), y.jia();
    x.p *= y.p, x.q *= y.q;
    x.hj();
    return x;
}
signed main() {
    // n * (1/1 + 1/2 + ... + 1/n)
    int n;
    cin >> n;
    frac ans;
    for (int i = 1; i <= n; i ++) {
        frac addon;
        addon.p = i, addon.q = n;
        ans = ans + addon;
    }
    ans.print();
    return 0;
}