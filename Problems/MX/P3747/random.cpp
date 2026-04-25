#include <bits/stdc++.h>
using namespace std;

int randint(int st, int ed) {
    static ifstream rand_dev("/dev/random", ios::binary);
    unsigned int x;
    rand_dev.read((char*)&x, sizeof(x));
    return st + x % (ed - st + 1);
}
int main() {
    int n = randint(1, 5e4);
    int m = randint(1, 5e4);
    int p = randint(1, 1e8);
    int c = randint(0, p);
    cout << n << " " << m << " " << p << " " << c << endl;
    for (int i = 1; i <= n; i ++)
        cout << randint(0, p) << " ";
    cout << endl;
    while (m --) {
        cout << randint(0, 1) << " "; 
        int l = randint(1, n);
        cout << l << " " << randint(l, n) << endl;
    }
    return 0;
}