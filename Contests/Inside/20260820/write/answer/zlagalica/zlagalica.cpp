#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 600;
char res[N + 5][N + 5];
int sr[N + 5], sc[N + 5];
struct Puzzle {
    char c;
    int r, s;
    bool u;
    int d;
} a[N + 5];
signed main() {
    freopen("zlagalica.in", "r", stdin);
    freopen("zlagalica.out", "w", stdout);
    int T;
    cin >> T;
    for (int i = 1; i <= T; i ++) 
        cin >> a[i].c >> a[i].r >> a[i].s >> a[i].u >> a[i].d;
    int curr = N, curc = 1;
    for (int t = 1; t <= T; t ++) {
        int now;
        cin >> now;
        for (int i = 1; i <= a[now].r; i ++)
            for (int j = 1; j <= a[now].s; j ++) {
                int nx = curr - a[now].r + i, ny = curc + j - 1;
                res[nx][ny] = a[now].c;
            }
        if (a[now].u == 0)
            curr -= a[now].r, curc += a[now].d - 1;
        else
            curc += a[now].s, curr -= a[now].r - a[now].d;
    }
    for (int i = 1; i <= N; i ++)
        for (int j = 1; j <= N; j ++)
            if (res[i][j])
                sr[i] ++, sc[j] ++;
    int r = 0, c = 0;
    for (int i = N; i >= 1; i --) 
        if (sr[i])
            r = i;
    for (int j = 1; j <= N; j ++) 
        if (sc[j])
            c ++;
    cout << N - r + 1 << " " << c << endl;
    for (int i = r; i <= N; i ++) {
        for (int j = 1; j <= c; j ++)
            if (res[i][j])
                cout << res[i][j];
            else
                cout << '.';
        cout << endl;
    }
    return 0;
}