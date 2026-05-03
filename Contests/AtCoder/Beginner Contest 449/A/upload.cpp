#include <bits/stdc++.h>
using namespace std;
#define int long long
const double pi = 3.141592653589793;
signed main() {
    int d;
    cin >> d;
    double r = d * 1.0 / 2;
    double S = pi * r * r;
    printf("%.15lf", S);
    return 0;
}