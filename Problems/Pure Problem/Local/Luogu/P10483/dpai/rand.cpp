#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	mt19937 rnd(atoi(argv[1]));
    int n = rnd() % 14 + 1, m = rnd() % (int)(1e5 + 7) + 1;
    cout << n << " " << m << endl;
    for (int i = 1; i <= n; i ++)
        cout << rnd() % m + 1 << endl;
    return 0;
}
