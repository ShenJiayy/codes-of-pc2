/*
I swear by GOD,
Promise to EXCHANGE my bro's 1000 years of his life for MY 100Points
Wish I got AC.

expected:100pts
*/
#include <bits/stdc++.h>
#define ull unsigned long long
#define forr(i, a, b) for (int i = a; i <= b; i++)
using namespace std;
ull n, m, c, k;
bitset<70> fed, lim;
ull ans = 0;
void Init()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
}
int main()
{
  freopen("zoo.in", "r", stdin);
  freopen("zoo.out", "w", stdout);
  Init();
  cin >> n >> m >> c >> k;
  for (ull i = 1; i <= n; i++)
  {
    ull a;
    cin >> a;
    fed |= a;
  }
  for (ull i = 1; i <= m; i++)
  {
    ull p, q;
    cin >> p >> q;
    lim[p] = 1;
  }
  for (ull i = 0; i < k; i++)
  {
    if (fed[i] || !lim[i])
      ans++;
  }
  if (ans == 64 && n == 0)
    cout << "18446744073709551616";
  else if (ans == 64)
    cout << (ull)(ULLONG_MAX - (n - 1ull));
  else
    cout << (ull)((1ull << ans) - n);
  return 0;
}