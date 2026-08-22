#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MOD = 998244353;
int a[100005];
int op[100005], p[100005], v[100005];
signed main()
{
	freopen("call.in", "r", stdin);
	freopen("call.out", "w", stdout);
    int n;
    cin>>n;
    for(int i = 1; i <= n; i++) cin>>a[i];
    int m;
    cin>>m;
    for(int i = 1; i <= m; i++)
    {
        cin>>op[i];
        if(op[i] == 1)
        {
            cin>>p[i]>>v[i];
            a[p[i]] += v[i];
            a[p[i]] %= MOD;
        }
        else if(op[i] == 2)
        {
            cin>>v[i];
            for(int j = 1; j <= n; j++)
            {
                a[j] *= v[i];
				a[j] %= MOD;
            }
        }
        else if(op[i] == 3)
        {
            int c;
            cin>>c;
            while(c--)
            {
                int x;
                cin>>x;
                if(op[x] == 1)
                {
                    a[p[x]] += v[x];
                    a[p[x]] %= MOD;
                }
                else
                {
                    for(int f = 1; f <= n; f++)
                    {
                        a[f] = a[f] * v[x] % MOD;
                    }
                }
            }
        }
        for(int i = 1; i <= n; i++)
	    {
	        cout<<a[i]<<' ';
	    }
	    cout<<endl;
    }
    for(int i = 1; i <= n; i++)
    {
        cout<<a[i]<<' ';
    }
}
