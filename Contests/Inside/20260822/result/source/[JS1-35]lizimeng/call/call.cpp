/*
I swear by GOD,
Promise to EXCHANGE my bro's 1000 years of his life for MY 100Points
Wish I got AC.

expected:100pts
*/
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define forr(i, a, b) for (int i = a; i <= b; i++)
const int maxN = 1e5 + 10;
const ll mod = 998244353;
void Init()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
}
using namespace std;
ll tr[4 * maxN], lzt[4 * maxN], lza[4 * maxN];
struct o1
{
  ll p, v;
};
struct o2
{
  ll v;
};
struct o3
{
  int c;
  vector<int> op;
};
o1 op1[maxN];
o2 op2[maxN];
o3 op3[maxN];
int typ[maxN];
queue<int> ord;
void init(int now)
{
  int cnt = op3[now].c;
  for (int i = 0; i < cnt; i++)
  {
    if (typ[op3[now].op[i]] == 3)
      init(op3[now].op[i]);
    else
      ord.push(op3[now].op[i]);
  }
}
void pushup(int u)
{
  tr[u] = (tr[u * 2] + tr[u * 2 + 1]) % mod;
}
void build(int u, int l, int r)
{
  if (l == r)
  {
    tr[l] = lza[l] = 0;
    lzt[l] = 1;
    return;
  }
  int mid = l + (r - l) / 2;
  build(u * 2, l, mid);
  build(u * 2 + 1, mid + 1, r);
  pushup(u);
}
void maketag(int u, int l, int r, ll mul, ll add)
{
  tr[u] = ((tr[u] % mod) * 1ll * (mul % mod)) % mod;
  tr[u] = (tr[u] + (r - l + 1) * add * 1ll) % mod;
  lzt[u] = (lzt[u] * mul) % mod;
  lza[u] = (lza[u] + add) % mod;
}
void pushdown(int u, int l, int r)
{
  if (l != r)
  {
    int mid = l + (r - l) / 2;
    maketag(u * 2, l, mid, lzt[u], lza[u]);
    maketag(u * 2 + 1, mid + 1, r, lzt[u], lza[u]);
    lzt[u] = 1;
    lza[u] = 0;
  }
}
void update(int u, int l, int r, int x, int y, ll mul, ll add)
{
  if (x <= l && r <= y)
  {
    maketag(u, l, r, mul, add);
    return;
  }
  pushdown(u, l, r);
  int mid = l + (r - l) / 2;
  if (mid >= x)
    update(u * 2, l, mid, x, y, mul, add);
  if (mid + 1 <= y)
    update(u * 2 + 1, mid + 1, r, x, y, mul, add);
  pushup(u);
}
ll query(int u, int l, int r, int x, int y)
{
  if (l >= x && r <= y)
  {
    return tr[u] % mod;
  }
  pushdown(u, l, r);
  ll ans = 0;
  int mid = l + (r - l) / 2;
  if (mid >= x)
    ans = (ans + query(u * 2, l, mid, x, y)) % mod;
  if (mid + 1 <= y)
    ans = (ans + query(u * 2 + 1, mid + 1, r, x, y)) % mod;
  return ans;
}
int n;
int main()
{
  Init();
  freopen("call.in", "r", stdin);
  freopen("call.out", "w", stdout);
  cin >> n;
  build(1, 1, n);
  for (int i = 1; i <= n; i++)
  {
    ll k;
    cin >> k;
    update(1, 1, n, i, i, 1, k);
  }
  int m;
  cin >> m;
  for (int i = 1; i <= m; i++)
  {
    int opt;
    cin >> opt;
    if (opt == 1)
    {
      cin >> op1[i].p >> op1[i].v;
      typ[i] = 1;
    }
    else if (opt == 2)
    {
      cin >> op2[i].v;
      typ[i] = 2;
    }
    else
    {
      cin >> op3[i].c;
      int o;
      for (int j = 1; j <= op3[i].c; j++)
      {
        cin >> o;
        op3[i].op.push_back(o);
      }
      typ[i] = 3;
    }
  }
  int q;
  cin >> q;
  for (int i = 1; i <= q; i++)
  {
    int opt;
    cin >> opt;
    if (typ[opt] == 1 || typ[opt] == 2)
      ord.push(opt);
    else
      init(opt);
  }
  while (!ord.empty())
  {
    int now = ord.front();
    ord.pop();
    if (typ[now] == 1)
    {
      update(1, 1, n, op1[now].p, op1[now].p, 1, op1[now].v);
    }
    else if (typ[now] == 2)
    {
      update(1, 1, n, 1, n, op2[now].v, 0);
    }
  }
  for (int i = 1; i <= n; i++)
    cout << query(1, 1, n, i, i) << " ";
  return 0;
}
