#include <cstdio>
#include <queue>
const int N = 2e5;
int a[N + 5];
std::queue<int> q[N + 5];
signed main() {
	int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++)
        scanf("%d", &a[i]);
    a[0] = !a[1];
    int curr = 0;
    for (int i = 1; i <= n; i ++) {
        if (a[i] != a[i - 1])
            curr ++;
        q[curr].push(i);
    }
    while (curr) {
        int lst = 0;
        for (int i = 1; i <= curr; i ++) {
            printf("%d ", q[i].front());
            q[i].pop();
            if (!q[i].empty()) {
                if (!q[lst].empty() && a[q[lst].front()] == a[q[i].front()])
                    while (!q[i].empty())
                        q[lst].push(q[i].front()), q[i].pop();
                else
                    lst = i;
            }
        }
        printf("\n");
        int ncur = 0;
        for (int i = 1; i <= curr; i ++)
            if (!q[i].empty())
                q[++ ncur] = q[i];
        curr = ncur;
    }
    return 0;
}