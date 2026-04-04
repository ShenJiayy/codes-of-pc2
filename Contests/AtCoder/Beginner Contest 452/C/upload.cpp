#include <bits/stdc++.h>
using namespace std;
// #define int long long
const int N = 1000, M = 2e5;
const string ans[2] = {"No\n", "Yes\n"};
int a[N + 5], b[N + 5];
string s[M + 5];
vector<string> p[N + 5];
bool exist[N + 5][N + 5][128]; // exist[i][j][k]表示第i组第j列有没有字符k
signed main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i] >> b[i];
    int m;
    cin >> m;
    for (int i = 1; i <= m; i ++) 
        cin >> s[i], p[s[i].size()].push_back(s[i]);
    for (int i = 1; i <= 10; i ++) 
        for (string str : p[i]) 
            for (int col = 0; col < str.size(); col ++) 
                exist[i][col][str[col]] = 1;
    for (int j = 1; j <= m; j ++) {
        if (s[j].size() != n) {
            cout << ans[0];
            continue;
        }
        bool flg = 1;
        for (int i = 1; i <= n; i ++) {
            bool res = 0;
            if (exist[a[i]][b[i] - 1][s[j][i - 1]]) 
                res = 1;
            flg = flg && res;
            if (flg == 0) break;
        }
        cout << ans[flg];
    }
    return 0;
}
