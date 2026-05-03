#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>
using namespace std;
#define int long long
struct myhash {
    static const int mod = 10009;
    int top;
    vector<int> idx, val, stk;
    int find(int x) {
        int h = x % mod;
        while (idx[h] != -1 && idx[h] != x) h ++;
        return h;
    }
    myhash() {
        top = 0;
        idx.resize(mod + 5, -1);
        val.resize(mod + 5, 0), stk.resize(mod + 5, 0);
    }
    void push(int k, int v) {
        int id = find(k);
        if (idx[id] == -1)
            idx[id] = k, val[id] = v, stk[++ top] = id;
    }
    int put(int x) {
        int id = find(x);
        if (idx[id] == x) return val[id];
        return -1;
    }
    void clear() {
        while (top) idx[stk[top --]] = -1;
    }
} hs;
struct trp {
    int gcd, x, y;
};
trp mkpair(int a, int b, int c) {
    trp ret;
    ret.gcd = a;
    ret.x = b;
    ret.y = c;
    return ret;
}
trp exgcd(int a, int b) {
    if (b == 0) 
        return mkpair(a, 1, 0);
    trp rt = exgcd(b, a % b);
    return mkpair(rt.gcd, rt.y, rt.x - a / b * rt.y);
}
inline int exbsgs(int a, int b, int c) {
    int tmp = 1, cnt = 0, d = 1;
    for (int i = 0; i < 32; i ++) {
        if (tmp == b) return i;
        tmp = tmp * a % c;
    }
    trp res = exgcd(a, c);
    while (res.gcd != 1) {
        if (b % res.gcd) return -1;
        b /= res.gcd, c /= res.gcd;
        d = d * a / res.gcd % c;
        res = exgcd(a, c);
        cnt ++;
    }
    int sqtn = static_cast<int>(ceil(sqrt(c)));
    hs.clear();
    int bs = 1;
    for (int i = 0; i < sqtn; i ++) {
        hs.push(bs, i);
        bs = bs * a % c;
    }
    for (int i = 0; i < sqtn; i ++) {
        res = exgcd(d, c);
        int cc = c / res.gcd;
        res.x = (res.x * b / res.gcd % cc + cc) % cc;
        int j = hs.put(res.x);
        if (j != -1) return i * sqtn + j + cnt;
        d = d * bs % c;
    }
    return -1;
}
inline int solve(int a, int b, int c) {
    // k >= z.
    if (b == 0) return -1;
    if (c >= b) c %= b;
    return exbsgs(a, c, b);
}
signed main() {
	while (1) {
        int x, z, k;
        cin >> x >> z >> k;
        if (x == 0 && z == 0 && k == 0) return 0;
        int ret = solve(x, z, k);
        if (ret == -1) cout << "No Solution\n";
        else cout << ret << endl;
    }
    return 0;
}