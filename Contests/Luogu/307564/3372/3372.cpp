#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5, INIT = 0;
int segt[N * 4 + 5], a[N + 5], tag[N * 4 + 5];
int operation(int x, int y) {
    return x + y;
}
void PushUp(int id) {
    segt[id] = operation(segt[id << 1], segt[id << 1 | 1]);
}
void PushDown(int id) {
    if (tag[id]) {
        tag[id << 1] += tag[id];
        tag[id << 1 | 1] += tag[id];
        segt[id << 1] += tag[id];
        segt[id << 1 | 1] += tag[id];
        tag[id] = 0; 
    }
}
void build(int l, int r, int id) {
    if (l == r)
        segt[id] = a[l];
    else {
        int mid = l + r >> 1;
        build(l, mid, id << 1);
        build(mid + 1, r, id << 1 | 1);
        PushUp(id);
    }
}
void UpdateNode(int id, int vl, int l, int r, int ti) {
    if (l == r)
        segt[ti] = operation(segt[ti], vl), a[id] = operation(a[id], vl);
    else {
        PushDown(id);
        int mid = l + r >> 1;
        if (id <= mid)
            UpdateNode(id, vl, l, mid, ti << 1);
        else
            UpdateNode(id, vl, mid + 1, r, ti << 1 | 1);
        PushUp(ti);
    }
}
int QueryDistrict(int l, int r, int tl, int tr, int id) {
    if (l <= tl && tr <= r)
        return segt[id];
    PushDown(id);
    int mid = tl + tr >> 1;
    int ans = INIT;
    if (l <= mid)
        ans = operation(ans, QueryDistrict(l, r, tl, mid, id << 1));
    if (mid < r)
        ans = operation(ans, QueryDistrict(l, r, mid + 1, tr, id << 1 | 1));
    return ans;
}
void UpdateDistrict(int l, int r, int vl, int tl, int tr, int id) {
    if (l <= tl && tr <= r) {
        tag[id] += vl;
        segt[id] += vl;
    }
    else {
        PushDown(id);
        int mid = tl + tr >> 1;
        if (l <= mid)
            UpdateDistrict(l, r, vl, tl, mid, id << 1);
        if (mid < r)
            UpdateDistrict(l, r, vl, mid + 1, tr, id << 1 | 1);
        PushUp(id);
    }
}
signed main() {
    #ifndef ONLINE_JUDGE
        freopen("in.in", "r", stdin);
    #endif

    return 0;
}