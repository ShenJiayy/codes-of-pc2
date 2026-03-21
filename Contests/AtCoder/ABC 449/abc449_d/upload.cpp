#include <bits/stdc++.h>
using namespace std;
#define int long long
int max(int i, int j, int k, int l) {
    return max(max(i, j), max(k, l));
}
signed main() {
    int l, r, u, d;
    cin >> l >> r >> d >> u;
    // (l, u) (l, d) (r, d) (r, u)
    int ans = (l <= 0 && 0 <= r && d <= 0 && 0 <= u);
    for (int i = 1; i <= max(abs(l), abs(r), abs(d), abs(u)); i ++) {
        // ?????????????
        // (i~1-i, -i), (-i, -i~i-1)
        // (-i~i-1, i), (i, i-1~-i)
        if (i % 2 == 1) continue ;
        for (int lne = i, col = -i; lne >= 1 - i; lne --)
            if ((l <= col && col <= r) && (d <= lne && lne <= u))
            	ans ++;
        for (int lne = -i, col = -i; col <= i - 1; col ++)
            if ((l <= col && col <= r) && (d <= lne && lne <= u))
            	ans ++;
        for (int lne = -i, col = i; lne <= i - 1; lne ++)
            if ((l <= col && col <= r) && (d <= lne && lne <= u))
            	ans ++;
        for (int lne = i, col = i; col >= 1 - i; col --)
            if ((l <= col && col <= r) && (d <= lne && lne <= u))
            	ans ++;
        /* Old Version Below:
        if (r >= -i && -i >= l) 
            ans += abs(min(i, u) - max(1 - i, d) + 1);
        if (u >= -i && -i >= d) // ...
            ans += abs(min(i - 1, r) - max(-i, l) + 1);
        if (l <= i && i <= r)
            ans += abs(min(i - 1, u) - max(-i, d) + 1);
        if (d <= i && i <= u) // ...
            ans += abs(min(i - 1, r) - max(-i, l) + 1);
        */
    }
    cout << ans;
    return 0;
}
