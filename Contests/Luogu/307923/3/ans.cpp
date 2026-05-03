#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll ;
 
ll read()
{
    ll x = 0, f = 1; char c = getchar();
    while(c < '0' || c > '9') { if(c == '-') f = -f; c = getchar(); }
    while(c >= '0' && c <= '9') { x = x * 10 + c - '0'; c = getchar(); }
    return x * f;
}
 
const int maxN = 100005;
ll n, m, a[maxN], block[maxN], lazy[maxN];
vector<ll>vt[maxN];
 
void reset(ll x) {
    vt[x].clear();
    for(ll i = (x - 1) * m + 1; i <= x * m; ++ i ) {
        vt[x].emplace_back(a[i]);
    }
    sort(vt[x].begin(), vt[x].end());
}
 
void add(ll l, ll r, ll val) {
    if(block[l] == block[r]) {
        for(ll i = l; i <= r; ++ i ) {
            a[i] += val;
        }
        reset(block[l]);
    } else {
        for(ll i = l; i <= block[l] * m; ++ i ) {
            a[i] += val;
        }
        reset(block[l]);
        for(ll i = (block[r] - 1) * m + 1; i <= r; ++ i ) {
            a[i] += val;
        }
        reset(block[r]);
        for(ll i = block[l] + 1; i <= block[r] - 1; ++ i ) {
            lazy[i] += val;
        }
    }
}
 
ll query(ll l, ll r, ll val) {
    ll ans = INT64_MIN;
    if(block[l] == block[r]) {
        for(ll i = l; i <= r; ++ i ) {
            if(a[i] + lazy[block[l]] < val) {
                ans = max(ans, a[i] + lazy[block[l]]);
            }
        }
    } else {
        for(ll i = l; i <= block[l] * m; ++ i ) {
            if(a[i] + lazy[block[l]] < val) {
                ans = max(ans, a[i] + lazy[block[l]]);
            }
        }
        for(ll i = (block[r] - 1) * m + 1; i <= r; ++ i ) {
            if(a[i] + lazy[block[r]] < val) {
                ans = max(ans, a[i] + lazy[block[r]]);
            }
        }
        for(ll i = block[l] + 1; i <= block[r] - 1; ++ i ) {
            ll id = lower_bound(vt[i].begin(), vt[i].end(), val - lazy[i]) - vt[i].begin();
            if(id) ans = max(ans, vt[i][id - 1] + lazy[i]);
        }
    }
    return ans == INT64_MIN ? -1 : ans;
}
 
int main()
{
    n = read(); m = sqrt(n);
    for(ll i = 1; i <= n; ++ i ) {
        a[i] = read();
        block[i] = (i - 1) / m + 1;
        vt[block[i]].emplace_back(a[i]);
    }
    for(ll i = 1; i <= block[n]; ++ i ) {
        sort(vt[i].begin(), vt[i].end());
    }
    for(ll i = 1; i <= n; ++ i ) {
        ll op, l, r, c;
        op = read(), l = read(), r = read(), c = read();
        if(!op) { //加
            add(l, r, c);
        } else { //query
            cout << query(l, r, c) << endl;
        }
    }
    return 0;
}