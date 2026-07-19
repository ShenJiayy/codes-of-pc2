#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(signed argc, char** argv) {
    mt19937 rnd(atoi(argv[1]));
    int n = rnd() % 10 + 1;
    cout << n << endl;
    for (int i = 1; i <= n; i ++)
        cout << rnd() % (int)(100) + 1 << " ";
    cout << endl;
    int T = n;
    while (T --) {
        int l, r;
        l = rnd() % n + 1, r = rnd() % n + 1;
        if (l > r) swap(l, r);
        cout << l << " " << r << endl;
    }
    return 0;
}