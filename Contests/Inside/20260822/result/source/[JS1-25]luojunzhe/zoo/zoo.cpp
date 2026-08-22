#include <bits/stdc++.h>
#define int unsigned long long
using namespace std;

signed main()
{
    freopen("zoo.in", "r", stdin);
    freopen("zoo.out", "w", stdout);
    int n, m, c, k;
    cin>>n>>m>>c>>k;
    int ljz = 0;
    for(int i = 1; i <= n; i++)
    {
        int q;
        cin>>q;
        ljz |= q;
    }
    int lbq = 0;
    for(int i = 1; i <= m; i++)
    {
        int x, y;
        cin>>x>>y;
        lbq |= (1 << x);
    }
    int cnt = 0;
    for(int i = 0; i < k; i++)
    {
        cnt += !((lbq >> i) & 1) || ((ljz >> i) & 1);
    }
    int ans = (1 << cnt) - n;
    cout<<cnt<<endl;
    cout<<ans;
    return 0;
}