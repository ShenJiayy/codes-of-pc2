#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, r, cnt, box[15];
void dfs(int id, int emp) {
    if (emp > n - id + 1) return;
    if (id > n) {
        if (emp == 0) 
            cnt ++;
        return ;
    }
    for (int i = 1; i <= r; i ++) {
        box[i] ++;
        if (box[i] == 1)
            emp --;
        dfs(id + 1, emp);
        box[i] --;
        if (box[i] == 0)
            emp ++;
    }
}
signed main() {
    cin >> n >> r;
    // n, r小
    // 没事的
    // 区区r^n次而已
    // 10^10顶天，外加优化
    dfs(1, r);
    cout << cnt;
    return 0;
}
