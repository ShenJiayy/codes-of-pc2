#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5;
struct Node {
    int nxt, val, id, cnt;
} a[N + 5];
bool cmp(Node x, Node y) {
    return x.val < y.val;
}
bool operator <(Node x, Node y) {
    if (x.cnt == y.cnt) return x.val > y.val;
    return x.cnt < y.cnt;
}
int main() {
	int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++)
        scanf("%d", &a[i].val);
    for (int i = 1; i <= n; i ++)
        scanf("%d", &a[i].nxt);
    for (int i = 1; i <= n; i ++)
        a[i].id = i;
    if (n == 2) {
        if (a[1].nxt == -1 && a[2].nxt == -1)
            printf("%d\n1 2", min(a[1].val, a[2].val));
        else printf("-1");
        return 0;
    }
    for (int i = 1; i <= n; i ++)
        if (a[i].nxt != -1)
            a[a[i].nxt].cnt ++;
    sort(a + 1, a + n + 1, cmp);
    priority_queue<Node> heap;
    for (int i = n / 2 + 1; i < n; i ++)
        heap.push(a[i]);
    if (heap.top().nxt != -1 && heap.top().cnt == n - 2) {
        printf("-1");
        return 0;
    }
    heap.push(a[n]);
    if (heap.top().cnt == n - 1) {
        printf("-1");
        return 0;
    }
    bool flg = 0;
    Node maxc = heap.top();
    for (int i = 1; i <= n / 2; i ++)
        if (a[i].nxt != maxc.id)
            flg = 1;
    if (flg) {
        ll ans = 0;
        for (int i = n / 2; i >= 1; i --)
            ans += 1ll * (n / 2 - i + 1) * a[i].val;
        printf("%lld\n", ans);
        for (int i = n  / 2; i >= 1; i --) {
            Node t = heap.top();
            if (a[i].nxt != t.id) {
                printf("%d %d\n", a[i].id, t.id);
                heap.pop();
            }
            else {
                heap.pop();
                printf("%d %d\n", a[i].id, t.id);
                heap.pop();
                heap.push(t);
            }
        }    
    }
    else {
        int pos;
        for (pos = n / 2 + 1; pos <= n; pos ++) {
            if (a[pos].val < maxc.val)
                if (a[pos].nxt != maxc.id)
                    break;
            if (a[pos].val > maxc.val)
                if (maxc.nxt != a[pos].id)
                    break;
        }
        ll ans = 0;
        ans += min(a[pos].val, maxc.val);
        for (int i = n / 2 - 1; i >= 1; i --)
            ans += 1ll * (n / 2 + 1 - i) * a[i].val;
        printf("%lld\n", ans);
        printf("%d %d", maxc.id, a[pos].id);
        heap.pop();
        for (int i = n / 2 - 1, j = n / 2; i >= 1 && j <= n; i --, j ++) {
            if (j == pos || a[j].val == maxc.val) j ++;
            printf("%d %d\n", a[i].id, a[j].id);
        }
    }
    return 0;
}