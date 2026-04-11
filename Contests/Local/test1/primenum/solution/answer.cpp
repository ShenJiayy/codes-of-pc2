#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e7 + 5;
bool is_prime[MAXN];
vector<int> primes;

void euler_sieve(int n) {
    memset(is_prime, true, sizeof(is_prime));
    is_prime[0] = is_prime[1] = false;
    primes.reserve(n / log(n)); // 预分配空间
    for (int i = 2; i <= n; ++i) {
        if (is_prime[i]) primes.push_back(i);
        for (int p : primes) {
            if (1LL * i * p > n) break;
            is_prime[i * p] = false;
            if (i % p == 0) break; // 保证仅被最小质因子筛去
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    euler_sieve(n);
    cout << primes.size() << endl;
    return 0;
}