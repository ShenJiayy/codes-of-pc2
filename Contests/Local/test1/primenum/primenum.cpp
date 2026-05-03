#include <bits/stdc++.h>
using namespace std;
const int N = 1e7;
bool isprime[N + 5];
int main() {
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
    int n;
    cin >> n;
    memset(isprime, 1, sizeof isprime);
    isprime[0] = isprime[1] = 0;
    for (int i = 2; i <= n; i ++)
        if (isprime[i])
            for (int j = i + i; j <= n; j += i)
                isprime[j] = 0;
    int cnt = 0;
    for (int i = 1; i <= n; i ++)
        cnt += isprime[i];
    cout << cnt;
    return 0;
}