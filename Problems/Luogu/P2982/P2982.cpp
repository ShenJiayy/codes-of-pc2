#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
vector<int> v[N + 5];
int s[N + 5], p[N + 5], n, ans[N + 5], a[N + 5];

int lowbit(int x) {
    return x & -x;
}

int GetSum(int id) {
    int sum = 0;
    for (; id; id -= lowbit(id))
        sum += s[id];
    return sum;
}

void AddNum(int p, int d) {
    for (; p <= n; p += lowbit(p))
        s[p] += d;
}

void dfs(int id, int ft) {
    int cow = a[id];
    ans[cow] = GetSum(cow - 1);
    AddNum(cow, 1);
    for (int next : v[id]) 
        if (next != ft)
            dfs(next, id);
    AddNum(cow, -1);
}

int main() {
    # ifndef ONLINE_JUDGE
        freopen("inputs\\1.txt", "r", stdin);
        freopen("output\\1.txt", "w", stdout);
    # endif
    cin >> n;
    for (int i = 1; i < n; i ++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for (int i = 1; i <= n; i ++)
        cin >> p[i];
    for (int i = 1; i <= n; i ++)
        a[p[i]] = i;
    dfs(1, 1);
    for (int i = 1; i <= n; i ++)
        cout << ans[i] << endl;
    return 0;
}