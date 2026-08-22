#include <bits/stdc++.h>
using namespace std;
int t, n, len;
int la[1000010], a[1000010];

int main()
{
	freopen("snakes.in", "r", stdin);
	freopen("snakes.out", "w", stdout);
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        cin >> n;
        if (i == 1)
        {
            len = n;
            for (int j = 1; j <= n; j++)
            {
                cin >> la[j];
                a[j] = la[j];
            }
        }
        else
        {
            for (int j = 1; j <= n; j++)
            {
                int x, y;
                cin >> x >> y;
                la[x] = y;
            }
            for (int j = 1; j <= len; j++)
            {
                a[j] = la[j];
            }
        }
        if (n == 3)
        {
            if (a[3] - a[1] < a[2])
            {
                cout << "3\n";
            }
            else
            {
                cout << "1\n";
            }
        }
        else
        {
            cout << "-1\n";
        }
    }
    return 0;
}
