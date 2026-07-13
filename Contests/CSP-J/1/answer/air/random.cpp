#include <bits/stdc++.h>
using namespace std;
int main() {
    int T = 10000;
    printf("%d\n", T);
    mt19937 rnd(time(0));
    while (T --) {
        int N = 100000, M = 100000, Q = 100000;
        printf("%d %d %d\n", N, M, Q);
        while (M --) {
            int l = rnd() % N + 1;
            int r = rnd() % N + 1;
            printf("%d %d\n", min(l, r), max(l, r));
        }
        vector<int> ls;
        for (int i = 1; i <= N; i ++)
            ls.push_back(i);
        shuffle(ls.begin(), ls.end(), rnd);
        for (int val : ls)
            printf("%d ", val);
        printf("\n");
    }
}
