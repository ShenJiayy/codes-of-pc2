#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

int main() {
	int n;
    ull k;
    cin >> n >> k;
    // 第x个bit循环为2^(x-1)[0]+2^(x-1)[1]+2^(x-1)[1]+2^(x-1)[0]
    const bool num[] = {0, 1, 1, 0};
    for (int i = n; i >= 1; i --) {
        cout << num[(k / (ull(1) << i - 1)) % 4];
    }
    return 0;
}
