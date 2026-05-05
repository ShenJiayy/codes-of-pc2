#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    long long tot = 1;
    for (int i = 0; i < n; i ++)
        tot = tot * (2 * n - i) / (i + 1);
    cout << tot / (n + 1);
}