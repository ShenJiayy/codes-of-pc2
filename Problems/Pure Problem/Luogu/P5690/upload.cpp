#include <iostream>
using namespace std;

signed main() {
	int cnt = 0;
    char x, y, z, u, _;
    cin >> x >> y >> _ >> z >> u;
    int a = x - '0', b = y - '0', c = z - '0', d = u - '0';
    if (a == 2 && b == 2 && c == 3 && d == 1) return puts("1"), 0;
    if (a == 0 && b == 0) b = 1, cnt ++;
    if (c == 0 && d == 0) d = 1, cnt ++;
    if (a >= 2 && b * 10 + c < 29) a = 0, cnt ++;
    if (a >= 2) a = 1, cnt ++;
    if (a == 1 && b > 2) b = 2, cnt ++;
    if (c > 3) c = 0, cnt ++;
    int m = a * 10 + b;
    if (m == 2 && c == 2 && d == 9) d = 8, cnt ++;
    if (m == 2 && c >= 3) c = 0, cnt ++;
    if (m == 4 || m == 6 || m == 9 || m == 11)
        if (c > 3) c = 2, cnt ++;
        else if (c == 3 && d) d = 0, cnt ++;
    if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
        if (c > 3) c = 2, cnt ++;
        else if (c == 3 && d > 1) d = 1, cnt ++;
    printf("%d", cnt);
    return 0;
}
