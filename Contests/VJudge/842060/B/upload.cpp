#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 4000;
int a[N + 5][N + 5];
int ac[N + 5][N + 5];
int ar[N + 5][N + 5];
signed main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++)
            cin >> a[i][j];
    int r, s;
    cin >> r >> s;
    deque<int> q;
    for (int i = 1; i <= n; i ++) {
        q.clear();
        for (int j = 1; j <= m; j ++) {
            while (!q.empty() && q.front() < j - r + 1)
                q.pop_front();
            while (!q.empty() && a[i][q.back()] < a[i][j])
                q.pop_back();
            q.push_back(j);
            if (j >= s)
                ar[i][j] = a[i][q.front()];
        }
    }
    for (int j = s; j <= m; j ++) {
        q.clear();
        for (int i = 1; i <= n; i ++) {
            while (!q.empty() && q.front() < j - r + 1)
                q.pop_front();
            while (!q.empty() && ar[i][q.back()] < ar[i][j])
                q.pop_back();
            q.push_back(j);
            if (i >= r)
                ac[i][j] = ar[i][q.front()];
        }
    }
    for (int i = r; i <= n; i ++) {
        for (int j = s; j <= m; j ++)
            cout << ac[i][j] << " ";
        cout << endl;
    }
    return 0;
}
