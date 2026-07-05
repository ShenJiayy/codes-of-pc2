#include <bits/stdc++.h>
using namespace std;
#define int long long

int run();

signed main() {
	int T;
    cin >> T;
    while (T --) {
        run();
        cout << endl;
    }
    return 0;
}




































const int N = 1e3;
struct Node {
    int num, id;
} a[N + 5], b[N + 5];
int x[N + 5], y[N + 5];
bool cmp1(Node x, Node y) {
    return x.num > y.num;
}
bool cmp2(Node x, Node y) {
    return x.num < y.num;
}
int run() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i].num, a[i].id = i;
    for (int i = 1; i <= n; i ++)
        cin >> b[i].num, b[i].id = i;
    sort(a + 1, a + n + 1, cmp1);
    sort(b + 1, b + n + 1, cmp2);
    int last = 0;
    for (int i = 1; i <= n; i ++) {
        last += a[i].num;
        if (last < b[i].num) {
            cout << "No";
            return 0;
        }
        x[i] = a[i].id, y[i] = b[i].id;
        last -= b[i].num;
    }
    cout << "Yes\n";
    for (int i = 1; i <= n; i ++)
        cout << x[i] << " ";
    cout << endl;
    for (int i = 1; i <= n; i ++)
        cout << y[i] << " ";
    return 0;
}