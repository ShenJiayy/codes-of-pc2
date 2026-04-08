#include <iostream>
#include <string>
using namespace std;

string dfs(int x) {
    if (x == 1) return "1";
    if (x == 2) return "2";
    if (x == 3) return "3";
    if (x == 5) return "5";
    if (x == 7) return "7";

    if (x % 2 == 0) return "(" + dfs(x / 2) + "*2)";
    if (x % 3 == 0) return "(" + dfs(x / 3) + "*3)";
    if (x % 5 == 0) return "(" + dfs(x / 5) + "*5)";
    if (x % 7 == 0) return "(" + dfs(x / 7) + "*7)";

    if (x - 2 >= 1) return "(" + dfs(x - 2) + "+2)";
    if (x - 3 >= 1) return "(" + dfs(x - 3) + "+3)";
    if (x - 5 >= 1) return "(" + dfs(x - 5) + "+5)";
    if (x - 7 >= 1) return "(" + dfs(x - 7) + "+7)";

    return "1";
}

int main() {
    int n;
    cin >> n;
    cout << dfs(n) << endl;
    return 0;
}