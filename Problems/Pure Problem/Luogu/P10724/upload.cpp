#include <bits/stdc++.h>
using namespace std;
#define int long long
const int table[] = {2, 3, 5, 7, 11, 13, 17, 19};
struct number {
    unsigned short a[15];
    /*
    void operator = (int x) {
        memset(a, 0, sizeof a);
        if (x == 1) return;
        if (x == 2) a[0] = 1;
        if (x == 3) a[1] = 1;
        if (x == 4) a[0] = 2;
        if (x == 5) a[2] = 1;
        if (x == 6) a[1] = a[0] = 1;
        if (x == 7) a[3] = 1;
        if (x == 8) a[0] = 3;
        if (x == 9) a[1] = 2;
        if (x == 10) a[0] = a[2] = 1;
        if (x == 11) a[4] = 1;
        if (x == 12) a[0] = 2, a[1] = 1;
        if (x == 13) a[5] = 1;
        if (x == 14) a[0] = a[3] = 1;
        if (x == 15) a[1] = a[2] = 1;
        if (x == 16) a[0] = 4;
        if (x == 17) a[6] = 1;
        if (x == 18) a[0] = 1, a[1] = 2;
        if (x == 19) a[7] = 1;
        if (x == 20) a[0] = 2, a[2] = 1;
        // 02  03  05  07  11  13  17  19  23  29
        //  0   1   2   3   4   5   6   7   8   9
        if (x == 21) a[1] = a[3] = 1;
        if (x == 22) a[0] = a[4] = 1;
        if (x == 23) a[8] = 1;
        if (x == 24) a[0] = 3, a[1] = 1;
        if (x == 25) a[2] = 2;
        if (x == 26) a[1] = a[5] = 1;
        if (x == 27) a[1] = 3;
        if (x == 28) a[0] = 2, a[3] = 1;
        if (x == 29) a[9] = 1;
        if (x == 30) a[0] = a[1] = a[2] = 1;
    }
    */
    void operator = (int x) {
        for (int i = 0; i < 10; i ++) {
            int bx = x;
            a[i] = 0;
            while (bx % table[i] == 0) bx /= table[i], a[i] ++;
        }
    }
    void operator = (number x) {
        for (int i = 0; i < 10; i ++) 
            a[i] = x.a[i];
    }
    void operator *= (number x) {
        for (int i = 0; i < 10; i ++)
            a[i] += x.a[i];
    }
    void operator /= (number x) {
        for (int i = 0; i < 10; i ++)
            a[i] -= x.a[i];
    }
    bool square() {
        for (int i = 0; i < 10; i ++) if (a[i] % 2) return 0;
        return 1;
    }
    number() { memset(a, 0, sizeof a); }
    number (int x) {
        for (int i = 0; i < 10; i ++) {
            int bx = x;
            a[i] = 0;
            while (bx % table[i] == 0) bx /= table[i], a[i] ++;
        }
    }
};
number operator * (number x, number y) {
    number z;
    z = x;
    z *= y;
    return z;
}
number operator / (number x, number y) {
    number z;
    z = x;
    z /= y;
    return z;
}
const int N = 1e5;
number a[N + 5], mul[N + 5];
bool valid[N + 5][1024];
signed main() {
	int n;
    cin >> n;
    number all;
    for (int i = 1; i <= n; i ++) {
        int x;
        cin >> x;
        all *= number(x);
        a[i] = x;
        mul[i] = mul[i - 1] * a[i];
        for (int st = 0; st < 1024; st ++) {
            valid[i][st] = 1;
            for (int j = 0; j < 10; j ++)
                if ((st << j & 1) && a[i].a[j] % 2)
                    valid[i][st] = 0;
            
        }
    }
    int cnt = 0;
    for (int i = 1; i <= n; i ++) {
        // 1~n 选定左端点 i
        number rall; rall = all / mul[i - 1];
        
    }
    return 0;
}