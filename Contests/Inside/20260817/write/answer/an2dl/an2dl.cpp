#include <bits/stdc++.h>
using namespace std;
const int N = 4000;
int a[N + 5][N + 5];
int main() {
    freopen("an2dl.in", "r", stdin);
    freopen("an2dl.out", "w", stdout);
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++)
            scanf("%d", &a[i][j]);
    int r, s;
    scanf("%d%d", &r, &s);
    map<int, int> mp;
    for (int i = r; i <= n; i ++) {
        for (int k = i - r + 1; k <= i; k ++)
            for (int j = 1; j <= s; j ++) 
                mp[a[k][j]] ++;
        for (int j = s; j <= m; j ++) {
            printf("%d ", (*mp.rbegin()).first);
            for (int k = i - r + 1; k <= i; k ++) {
                mp[a[k][j - s + 1]] --;
                if (mp[a[k][j - s + 1]] == 0)
                    mp.erase(a[k][j - s + 1]);
            }
            if (j < m)
                for (int k = i - r + 1; k <= i; k ++) 
                    mp[a[k][j + 1]] ++;
        }
        mp.clear();
        printf("\n");
    }
    return 0;
}