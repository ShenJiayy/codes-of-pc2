#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	mt19937 rnd(atoi(argv[1]));
    const int N = 3e5, M = 998244353;
    int n = rnd() % N + 1, m = rnd() % N + 1;
    cout << n << " " << m << endl;
    for (int i = 1; i <= n; i ++)
        cout << rnd() % M + 1 << " ";
    cout << endl;
    for (int i = 1; i <= m; i ++)
        cout << rnd() % M + 1 << " ";
    return 0;
}
