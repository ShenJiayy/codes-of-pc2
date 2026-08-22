#include <bits/stdc++.h>
#define I int
#define AK main()
#define IOI return
#define IMO runit();
using namespace std;
const int MOD = 998244353;
int n, m, q, b, tot;
long long a[100010], lt[400];
int id[100010], l[400], r[400];
struct func
{
    int t, p, v, c;
    vector<int> vv;
}fc[100010];

void pd()
{
    for (int i = 1; i <= n; i++)
    {
        cout << (a[i] * lt[id[i]] % MOD) << " ";
    }
    cout << "\n";
}

void run(int ind)
{
    cin.tie(0), cout.tie(0), ios::sync_with_stdio(NULL);
    if (fc[ind].t == 1)
    {
        int p = fc[ind].p;
        if (lt[id[p]] != 1)
        {
            for (int j = l[id[p]]; j <= r[id[p]]; j++)
            {
                a[j] = a[j] * lt[id[p]] % MOD;
            }
            lt[id[p]] = 1;
        }
        a[p] = a[p] + fc[ind].v % MOD;
    }
    else if (fc[ind].t == 2)
    {
        for (int i = 1; i <= tot; i++)
        {
            lt[i] = lt[i] * fc[ind].v % MOD;
        }
    }
    else
    {
        for (auto i : fc[ind].vv)
        {
            run(i);
        }
    }
}

int runit()
{
	freopen("call.in", "r", stdin);
	freopen("call.out", "w", stdout);
    cin.tie(0), cout.tie(0), ios::sync_with_stdio(NULL);
    cin >> n;
    b = sqrt(n);
    tot = (b + n - 1) / b;
    for (int i = 1; i <= tot; i++)
    {
        l[i] = (i-1) * b + 1;
        r[i] = min(i * b, n);
        lt[i] = 1;
        for (int j = l[i]; j <= r[i]; j++)
        {
            id[j] = i;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> fc[i].t;
        switch (fc[i].t)
        {
            case 1:
                cin >> fc[i].p >> fc[i].v;
                break;
            case 2:
                cin >> fc[i].v;
                break;
            case 3:
                cin >> fc[i].c;
                for (int k = 1; k <= fc[i].c; k++)
                {
                    int g;
                    cin >> g;
                    fc[i].vv.push_back(g);
                }
                break;
        }
    }
    cin >> q;
    for (int i = 1; i <= q; i++)
    {
        int x;
        cin >> x;
        run(x);
    }
    pd();
    return 0;
}

I AK {IOI IMO}
/*
xi wang Hex_233 de ping ce ji kuai yi dian, shu ju shui yi dian , 
rang wo de chao jue fen kui ka guo qu, wo bu hui xie xian duan shu !!
*/
