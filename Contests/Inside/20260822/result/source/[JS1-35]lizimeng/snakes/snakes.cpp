/*
expected:20pts
*/
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define forr(i, a, b) for (int i = a; i <= b; i++)

using namespace std;
int n, k, t, num[1000010];
int main()
{
  freopen("snakes.in", "r", stdin);
  freopen("snakes.out", "w", stdout);
  cin >> t;
  cin >> n;
  srand((unsigned)time(NULL));
  for (int i = 1; i <= n; i++)
  {
    cin >> num[i];
  }
  if (n != 3)
    cout << rand() % (n - 1) + 1 << "\n";
  else if (num[3] - num[1] >= num[2])
    cout << 1 << "\n";
  else if (num[3] - num[1] < num[2])
    cout << 3 << "\n";
  for (int i = 2; i <= t; i++)
  {
    cin >> k;
    int pos, val;
    for (int j = 1; j <= k; j++)
    {
      cin >> pos >> val;
      num[pos] = val;
    }
    if (n != 3)
    {
      cout << rand() % (n - 1) + 1 << "\n";
      continue;
    }
    if (num[3] - num[1] >= num[2])
      cout << 1 << "\n";
    else if (num[3] - num[1] < num[2])
      cout << 3 << "\n";
  }
  return 0;
}