#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
namespace sol
{
    template <class ccf>
    inline ccf qr(ccf ret)
    {
        ret = 0;
        register char c = getchar();
        while (c < 48 || c > 57)
            c = getchar();
        while (c >= 48 && c <= 57)
            ret = ret * 10 + c - 48, c = getchar();
        return ret;
    }
    inline ll qr() { return qr(1ll); }
    map<ll, int> mp;
    struct R
    {
        set<int> data;
        int f;
    } r[200001];
    inline int q(const int &x)
    {
        register int t = x, i = x, temp;
        while (r[t].f ^ t)
            t = r[t].f;
        while (r[i].f ^ i)
        {
            if (r[i].data.size())
            {
                r[t].data.insert(r[i].data.begin(), r[i].data.end());
                r[i].data.clear();
            }
            temp = r[i].f, r[i].f = t, i = temp;
        }
        return t;
    }
    inline void j(int t1, int t2)
    {
        if (r[t1].f == r[t2].f)
            return;
        if (r[t1].data.size() < r[t2].data.size())
            swap(t1, t2);
        for (auto t : r[t2].data)
            r[q(t)].data.insert(t1);
        r[t1].data.insert(r[t2].data.begin(), r[t2].data.end());
        r[t2].data.clear();
        r[t2].f = t1;
    }
    int main()
    {
        int n = qr();
        int cnt = 0;
        bool f = 1;
        mp.clear();
        for (register int t = 1; t <= n * 2; ++t)
            r[t].f = t, r[t].data.clear();
        for (register int t = 1, t0, t1, t2; t <= n; ++t)
        {
            t1 = qr();
            t2 = qr();
            t0 = qr();
            if (not f)
                continue;
            t1 = mp.find(t1) == mp.end() ? mp[t1] = ++cnt : mp[t1];
            t2 = mp.find(t2) == mp.end() ? mp[t2] = ++cnt : mp[t2];
            if (t1 = q(t1), t2 = q(t2), t0)
                if (r[t1].data.find(t2) != r[t1].data.end())
                    f = 0;
                else
                    j(t1, t2);
            else if (t1 == t2)
                f = 0;
            else
                r[t1].data.insert(t2), r[t2].data.insert(t1);
        }
        if (f)
            puts("YES");
        else
            puts("NO");
        return 0;
    }
} // namespace sol

int main()
{
    for (register int T = sol::qr(); T; T--)
        sol::main();
    return 0;
}