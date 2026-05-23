#include <bits/stdc++.h>
using namespace std;
#define int long long
int box[30];
// int solve() {
//     memset(box, 0, sizeof box);
//     string inp;
//     cin >> inp;
//     for (char c : inp)
//         box[c - 'a'] ++;
//     sort(box, box + 26);
//     int front = 0;
//     for (int i = 0; i < 26; i ++) {
//         if (box[i] > front + 1)
//             return puts("No"), 0;
//         front += box[i];
//     }
//     puts("Yes");
//     return 0;
// }
int solve() {
    memset(box, 0, sizeof box);
    string inp;
    cin >> inp;
    int n = inp.size();
    for (char c : inp)
        box[c - 'a'] ++;
    int pn = 0;
    string res;
    while (pn != n) {
        for (int i = 0; i < 26; i ++)
            if (box[i])
                if (*(res.end() - 1) != i + 'a')
                    res += char(i + 'a'), pn ++, box[i] --;
                else 
                    return puts("No"), 0;
        for (int i = 24; i >= 0; i --)
            if (box[i])
                if (*(res.end() - 1) != i + 'a')
                    res += char(i + 'a'), pn ++, box[i] --;
                else 
                    return puts("No"), 0;
    }
    cout << "Yes\n" << res << endl;
    return 0;
}
signed main() {
	int T;
    cin >> T;
    while (T --) solve();
    return 0;
}
