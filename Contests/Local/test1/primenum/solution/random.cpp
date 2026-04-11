#include <bits/stdc++.h>
using namespace std;
const int mod = 1e7;
int main(int argc, char** argv) {
    mt19937 rnd(atoi(argv[1]));
    cout << rnd() % mod + 1;
    return 0;
}