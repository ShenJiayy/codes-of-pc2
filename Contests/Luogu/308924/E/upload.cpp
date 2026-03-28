#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5;
int a[N + 5], b[N + 5];
int heap[N + 5], hpsize;
void tup(int x) {
    while (x > 1) {
        int ft = x >> 1;
        if (heap[ft] < heap[x]) {
            swap(heap[x], heap[ft]);
            x = ft;
        } 
		else break;
    }
}
void tdown(int x) {
    while ((x << 1) <= hpsize) {
        int c = x << 1;
        if (c + 1 <= hpsize && heap[c + 1] > heap[c]) c ++;
        if (heap[c] > heap[x]) {
            swap(heap[c], heap[x]);
            x = c;
        } 
		else break;
    }
}
void push(int x) {
    heap[++ hpsize] = x;
    tup(hpsize);
}
void pop() {
    swap(heap[hpsize], heap[1]);
    hpsize --;
    tdown(1);
}
int top() {
	return heap[1];
}
int size() {
	return hpsize;
}
signed main() {
    #ifndef ONLINE_JUDGE
        freopen("in.in", "r", stdin);
    #endif
    // Write here.
    int n;
    scanf("%lld", &n);
    for (int i = 1; i <= n; i ++)
        scanf("%lld", a + i);
    for (int i = 1; i <= n; i ++)
        scanf("%lld", b + i);
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= n; j ++) {
            if (size() < n)
                push(a[i] + b[j]);
            else if (top() > a[i] + b[j])
                push(a[i] + b[j]);
            else break;
        }
    vector<int> v;
    while (size() > 0) {
        v.push_back(top());
        pop();
    }
    reverse(v.begin(), v.end());
    for (int i = 0; i < n; i ++)
        printf("%lld ", v[i]);
    return 0;
}