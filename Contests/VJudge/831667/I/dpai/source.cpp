#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
const int N = 300000, blkCnt = 550;
int a[N + 5];
int blkid[N + 5], blkst[blkCnt + 5], blked[blkCnt + 5];
map<int, int> blknc[blkCnt + 5];
pii zs[blkCnt + 5];
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
	int n;
    cin >> n;
    int len = sqrt(n), blkc = n / len + n % len;
    for (int i = 1; i <= n; i ++)
        cin >> a[i], blkid[i] = i / len + 1;
    
    blkst[1] = 1;
    for (int i = 1; i < blkc; i ++)
        blked[i] = blkst[i] + len - 1,
        blkst[i + 1] = blked[i] + 1;
    blked[blkc] = n;
    
    for (int i = 1; i <= blkc; i ++) {
        map<int, int> mmp;
        for (int j = blkst[i]; j <= blked[i]; j ++)
            mmp[a[j]] ++;
        int maxid = 0, maxn = 0;
        for (pii val : mmp)
            if (maxn < val.first)
                maxn = val.first, maxid = val.second;
        zs[i] = {maxid, maxn};
        blknc[i] = mmp;
    }

    int T = n;
    while (T --) {
        int l, r;
        cin >> l >> r;
        int bl = blkid[l], br = blkid[r];
        int blr = blked[bl], brl = blkst[br];
        int ans = 9e18, cnt = 0;
        for (int i = l; i <= blr; i ++) {
            int res = 0;
            for (int j = l; j <= blr; j ++)
                if (a[j] == a[i])
                    res ++;
            for (int j = bl + 1; j < br; j ++)
                res += blknc[j][a[i]];
            for (int j = brl; j <= r; j ++)
                if (a[j] == a[i])
                    res ++;
            if (res > cnt || res == cnt && ans > a[i])
                ans = a[i], cnt = res;
        }
        for (int i = bl + 1; i < br; i ++) {
            int res = 0;
            for (int j = l; j <= blr; j ++)
                if (a[j] == zs[i].first)
                    res ++;
            for (int j = bl + 1; j < br; j ++)
                res += blknc[j][zs[i].first];
            for (int j = brl; j <= r; j ++)
                if (a[j] == zs[i].first)
                    res ++;
            if (res > cnt || res == cnt && ans > zs[i].first)
                ans = zs[i].first, cnt = res;
        }
        for (int i = brl; i <= r; i ++) {
            int res = 0;
            for (int j = l; j <= blr; j ++)
                if (a[j] == a[i])
                    res ++;
            for (int j = bl + 1; j < br; j ++)
                res += blknc[j][a[i]];
            for (int j = brl; j <= r; j ++)
                if (a[j] == a[i])
                    res ++;
            if (res > cnt || res == cnt && ans > a[i])
                ans = a[i], cnt = res;
        }
        cout << ans << endl;
    }
    return 0;
}
