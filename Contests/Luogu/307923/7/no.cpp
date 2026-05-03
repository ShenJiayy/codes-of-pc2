#include <bits/stdc++.h>
using namespace std;

const int N = 300005, M = 1005, MOD = 10007;
int n, block_size, blocks;
int a[N], belong[N], l[M], r[M], add[M], mul[M];

void build() {
    block_size = sqrt(n);
    blocks = (n + block_size - 1) / block_size;
    for (int i = 1; i <= blocks; i++) {
        l[i] = (i - 1) * block_size + 1;
        r[i] = min(n, i * block_size);
        mul[i] = 1;
        add[i] = 0;
        for (int j = l[i]; j <= r[i]; j++)
            belong[j] = i;
    }
}

void push_down(int block) {
    for (int i = l[block]; i <= r[block]; i++)
        a[i] = (a[i] * mul[block] + add[block]) % MOD;
    mul[block] = 1;
    add[block] = 0;
}

void update_add(int lft, int rght, int c) {
    int bl = belong[lft], br = belong[rght];
    if (bl == br) {
        push_down(bl);
        for (int i = lft; i <= rght; i++)
            a[i] = (a[i] + c) % MOD;
    } else {
        push_down(bl);
        for (int i = lft; i <= r[bl]; i++)
            a[i] = (a[i] + c) % MOD;
        for (int i = bl + 1; i < br; i++)
            add[i] = (add[i] + c) % MOD;
        push_down(br);
        for (int i = l[br]; i <= rght; i++)
            a[i] = (a[i] + c) % MOD;
    }
}

void update_mul(int lft, int rght, int c) {
    int bl = belong[lft], br = belong[rght];
    if (bl == br) {
        push_down(bl);
        for (int i = lft; i <= rght; i++)
            a[i] = (a[i] * c) % MOD;
    } else {
        push_down(bl);
        for (int i = lft; i <= r[bl]; i++)
            a[i] = (a[i] * c) % MOD;
        for (int i = bl + 1; i < br; i++) {
            mul[i] = (mul[i] * c) % MOD;
            add[i] = (add[i] * c) % MOD;
        }
        push_down(br);
        for (int i = l[br]; i <= rght; i++)
            a[i] = (a[i] * c) % MOD;
    }
}

int query(int pos) {
    int block = belong[pos];
    return (a[pos] * mul[block] + add[block]) % MOD;
}

signed main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] %= MOD;
    }
    build();
    for (int i = 1; i <= n; i++) {
        int op, l, r, c;
        cin >> op >> l >> r >> c;
        if (op == 0)
            update_add(l, r, c % MOD);
        else if (op == 1)
            update_mul(l, r, c % MOD);
        else
            cout << (query(r) % MOD + MOD) % MOD << endl;
    }
    return 0;
}
