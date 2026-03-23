#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5;
struct Node {
    int nxt, val, id, cnt;
} a[N + 5];
bool cmp(Node x, Node y) {
    return x.val < y.val;
}
bool operator <(Node x, Node y) {
    if (x.cnt == y.cnt) return x.id > y.id;
    return x.cnt < y.cnt;
}
int Solution1(int n, priority_queue<Node> heap) {
    int ans = 0;
    for (int i = n / 2; i >= 1; i --)
        ans += (n / 2 - i + 1) * a[i].val;
    printf("%lld\n", ans);
    for (int i = n  / 2; i >= 1; i --) {
        Node t = heap.top();
        if (a[i].nxt != t.id) {
            printf("%lld %lld\n", a[i].id, t.id);
            heap.pop();
        }
        else {
            heap.pop();
            printf("%lld %lld\n", a[i].id, t.id);
            heap.pop();
            heap.push(t);
        }
    }
    return 0;
}
int Solution2(int n, priority_queue<Node> heap) {
    Node t = heap.top();
    int pos;
    for (pos = n / 2 + 1; pos <= n; pos ++) {
        if (a[pos].val < t.val)
            if (a[pos].nxt != t.id)
                break;
        if (a[pos].val > t.val)
            if (t.nxt != a[pos].id)
                break;
    }
    int ans = 0;
    ans += min(a[pos].val, t.val);
    for (int i = n / 2 - 1; i >= 1; i --)
        ans += (n / 2 + 1 - i) * a[i].val;
    printf("%lld\n", ans);
    printf("%lld %lld", t.id, a[pos].id);
    heap.pop();
    for (int i = n / 2 - 1, j = n / 2; i >= 1 && j <= n; i --, j ++) {
        if (j == pos || a[j].val == t.val) j ++;
        printf("%lld %lld\n", a[i].id, a[j].id);
    }
    return 0;
}
signed main() {
	int n;
    scanf("%lld", &n);
    for (int i = 1; i <= n; i ++)
        scanf("%lld", &a[i].val);
    for (int i = 1; i <= n; i ++)
        scanf("%lld", &a[i].nxt);
    if (n == 2) {
        if (a[1].nxt != a[2].nxt && a[2].nxt != -1)
            printf("%lld\n1 2", min(a[1].val, a[2].val));
        else puts("-1");
        return 0;
    }
    for (int i = 1; i <= n; i ++)
        a[i].id = i;
    for (int i = 1; i <= n; i ++)
        if (a[i].nxt != -1)
            a[a[i].nxt].cnt ++;
    // 删除的东西，大的在前，小的在后
    sort(a + 1, a + n + 1, cmp);
    priority_queue<Node> heap;
    for (int i = n / 2 + 1; i <= n - 1; i ++)
        heap.push(a[i]);
    if (heap.top().nxt != -1 && heap.top().cnt == n - 2) {
        puts("-1");
        return 0;
    }
    heap.push(a[n]);
    if (heap.top().cnt == n - 1) {
        puts("-1");
        return 0;
    }
    bool flg = 0;
    Node maxc = heap.top();
    for (int i = 1; i <= n / 2; i ++)
        if (a[i].nxt != maxc.id)
            flg = 1;
    if (flg) return Solution1(n, heap); // 这个时候maxc还不能解锁全部
    else return Solution2(n, heap);
    return 0;
}


/*
首先，我们假设，没有不能配对的水晶，那么我们可以很容易想到一个贪心思路：

因为每次只计算能量值小的水晶，也就是说，只要排序后在前半段中找数和后半段随便找一个数配对即可，而且要从大到小选择。

简单证明一下，首先第一个很显然，如果把其中两对按“一前一后”配对的数换成“两前”和“两后”，那结果就由两个在前半段的数换成一个后半段和前半段的数统计而来，很明显不是最优的。

第二个，这个可以联系“排队接水”问题的贪心策略，假设我们给能量值为 x 和 y 的两个出现在前半段的水晶分别在第 k 和 k+1次销毁（后半段的很明显不用考虑），若 x<y，那么

先销毁 x 再销毁 y 的代价：
kx+(k+1)y=k(x+y)+y
先销毁 y 再销毁 x 的代价：
ky+(k+1)x=k(x+y)+x
因为 x<y，所以很明显先销毁大的更优。

现在加入了限制条件，说有些水晶不能同时销毁，但是，题目还有一个很重要的条件：对于每个水晶，有很多不能和它一起销毁，但其中能量值比它大的只有一个。

如果一个水晶不能和所有水晶配对，那此情况无解，除此之外，不存在无解的可能，因为这些不能配对的水晶最多只能连成一棵树，除了菊花图以外，不可能找到有点无法配对的情况，只要顺序合理，一定有解。

我们称有和后半段水晶不能配对的前半段水晶称为“锁定的水晶”，配对一对水晶，让前半段的一些水晶不被锁定称为“解锁”（当时我思考时用的词，这里顺着思路说下来）

而我们只要将“一前一后”地配对，而后半段的水晶无论怎么选都不会影响结果，所以只要后半段不存在能锁定前半段全部水晶的水晶，就一定可以一前一后地配对完所有水晶，而不会影响结果。

至于这种情况的构造方法，很明显，只要保证后半段没有水晶会锁定前半段剩余所有水晶即可。在此基础上思考构造策略即可，为方便实现，我们在每次配对时，都选择能解锁水晶最多的水晶。

如果有一颗后半段的水晶锁定了前半段所有水晶，我们只要先用一个能与这个水晶配对的最小的水晶先与之配对，一定要先配这对，因为很明显这对的能量值是最大的。

很明显这对水晶一定是后半段的，然后我们只要将分界点前移，此时前半段所有点都已被解锁，接下来就可以完全自由地配对了。
*/