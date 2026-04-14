// Windows is SHIT, IIS is SHIT, MinGW For Windows is SHIT
// Only Linux can save the world
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 3e6 + 5;
int inv[N];
static char buf[N * 12];
inline void write(int x, char*& p) {
    char tmp[12], *t = tmp;
    while (x) {
        *t++ = x % 10 + '0';
        x /= 10;
    }
    while (t != tmp) *p++ = *--t;
    *p++ = '\n';
}
signed main() {
    int n, p;
    scanf("%lld%lld", &n, &p);
    inv[1] = 1;
    for (int i = 2; i <= n; ++i)
        inv[i] = (p - p / i) * inv[p % i] % p;
    char *ptr = buf;
    for (int i = 1; i <= n; ++i)
        write(inv[i], ptr);
    fwrite(buf, 1, ptr - buf, stdout);
    return 0;
}