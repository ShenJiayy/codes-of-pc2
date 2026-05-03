#include <bits/stdc++.h>
using namespace std;
const int N = 1e3;
int f[2 * N + 5];
bool vis[N + 5];
void init(int n) {
    for (int i = 1; i <= n; i ++)
        f[i] = i;
}
int find(int id) {
    if (f[id] != id)
        f[id] = find(f[id]);
    return f[id];
}
void merge(int x, int y) {
    int ftx = find(x), fty = find(y);
    if (ftx != fty)
        f[ftx] = fty;
}
int main() {
    int n, m;
    cin >> n >> m;
    init(n * 2);
    for (int i = 1; i <= m; i ++) {
        char opt;
        int x, y;
        cin >> opt >> x >> y;
        if (opt == 'F') 
            f[find(x)] = find(y);
        else
            f[find(x + n)] = find(y), f[find(y + n)] = find(x);
    }
    int sum = 0;
    for (int i = 1; i <= n; i ++)
        sum += f[i] == i;
    cout << sum;
    return 0;
}