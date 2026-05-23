#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5;
char s[N + 5];
int ss[N + 5];
int GetTask(int n) {
    if (n <= 1000) return -14;
    if (n % 3 == 0) {
        bool valid = 1;
        for (int i = 1; i <= n; i += 3)
            if (!(s[i] == 'J' && s[i + 1] == 'O' && s[i + 2] == 'I'))
                valid = 0;
        if (valid)
            return -27;
    }
    cerr << "[E] This program can't process this subtask! (Subtask 3、4)";
    exit(0);
}
void process(int n) {
    for (int i = 1; i <= n; i ++)
        if (s[i] == 'J' && s[i + 1] == 'O' && s[i + 2] == 'I') {
            s[i] = 'O'; 
			s[i + 1] = 'I'; 
			s[i + 2] = 'J';
            i += 3;
        }
    bool will = 0;
    for (int i = 1; i <= n; i ++)
        if (s[i] == 'J' && s[i + 1] == 'O' && s[i + 2] == 'I')
            will = 1;
    if (will == 1)
        process(n);
}
signed main() {
    int n;
    cin >> n >> s + 1;
    int tsk = GetTask(n);
    if (tsk == -14) {
        process(n);
        printf("%s", s + 1);
        return 0;
    }
    if (tsk == -27) { // OI*(n/3)+J*(n/3)
        int k = n / 3;
        for (int i = 1; i <= k; i ++)
            cout << "OI";
        for (int i = 1; i <= k; i ++)
            cout << "J";
        return 0;
    }
    return 0;
}