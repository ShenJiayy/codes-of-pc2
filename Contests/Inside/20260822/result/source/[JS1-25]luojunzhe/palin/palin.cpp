#include <bits/stdc++.h>
using namespace std;
int t, n, l, r;
int a[1000005];
char ans[1000005];
bool solve(int l1, int r1, int l2, int r2)
{
    for(int i = 1; i < n; i++)
    {
        if(l1 < r1 && a[l1] == a[r1])
        {
            ans[i] = 'L';
            l1++;
            ans[2 * (n - 1) - i + 1] = 'L';
            r1--;
        }
        else if(l1 <= r1 && l2 <= r2 && a[l1] == a[l2])
        {
            ans[i] = 'L';
            l1++;
            ans[2 * (n - 1) - i + 1] = 'R';
            l2++;
        }
        else if(l2 <= r2 && l1 <= r1 && a[r2] == a[r1])
        {
            ans[i] = 'R';
            r2--;
            ans[2 * (n - 1) - i + 1] = 'L';
            r1--;
        }
        else if(l2 < r2 && a[l2] == a[r2])
        {
            ans[i] = 'R';
            l2++;
            ans[2 * (n - 1) - i + 1] = 'R';
            r2--;
        }
        else return 0;
    }
    return 1;
}
int main()
{
    freopen("palin.in", "r", stdin);
    freopen("palin.out", "w", stdout);
    int T;
    cin>>T;
    while(T--)
    {
        int x1, x2;
        cin>>n;
        for(int i = 1; i <= 2 * n; i++) cin>>a[i];
        memset(ans, 0, sizeof(ans));
        for(int i = 2; i <= 2 * n; i++)
        {
            if(a[1] == a[i])
            {
                x1 = i;
                break;
            }
        }
        for(int i = 2; i < 2 * n; i++)
        {
            if(a[2 * n] == a[i])
            {
                x2 = i;
                break;
            }
        }
        if(solve(2, x1 - 1, x1 + 1, 2 * n))
        {
            printf("L%sL\n", ans + 1);
        }
        else if(solve(1, x2 - 1, x2 + 1, 2 * n - 1))
        {
            printf("R%sL\n", ans + 1);
        }
        else{
            printf("-1\n");
        }
    }
    return 0;
}