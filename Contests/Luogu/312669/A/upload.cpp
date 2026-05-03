#include <bits/stdc++.h>
using namespace std;
#define int long long
int min(int a, int b, int c) { return min(min(a, b), c); }
signed main() {
	int n, q;
    cin >> n >> q;
    int sl, sd, sr, jl, jr, jd, pl, pr, pd, ml, mr, md;
    sl = sd = sr = jl = jd = jr = pl = pd = pr = ml = md = mr = 0;
    while (q --) {
        char opt;
        int x;
        cin >> opt >> x;
        if (opt == 'L') {
            sl += x, ml = max(ml, x);
            if ((n + n % 2) / 2 == x) jl ++;
            if ((n + n % 2) / 2 - 1 == x) pl ++;
        }
        if (opt == 'R') {
            sr += x, mr = max(mr, x);
            if ((n + n % 2) / 2 == x) jr ++;
            if ((n + n % 2) / 2 - 1 == x) pr ++;
        }
        if (opt == 'D') {
            sd += x, md = max(md, x);
            if (n == x) jd ++;
        }
    }
    int maxn = max(sl + sd, sr + sd), minn = 0;
    if (n % 2 == 0 && ml + mr == n)
        minn = min(jl, jr) + jd;
    else if (n % 2 && ml + mr >= n)
        minn = min(jl + jr,  jl * 2 + pl, jr * 2 + pr) + jd;
    else if (md == n)
        minn = jd;
    cout << maxn - minn;    
    return 0;
}
