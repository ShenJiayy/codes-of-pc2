#include <bits/stdc++.h>
using namespace std;
#define int long long
int which(char c) {
    if ('a' <= c && c <= 'c') return 2;
    if ('d' <= c && c <= 'f') return 3;
    if ('g' <= c && c <= 'i') return 4;
    if ('j' <= c && c <= 'l') return 5;
    if ('m' <= c && c <= 'o') return 6;
    if ('p' <= c && c <= 's') return 7;
    if ('t' <= c && c <= 'v') return 8;
    if ('w' <= c && c <= 'z') return 9;
    return 1;
}
signed main() {
	int T;
    cin >> T;
    while (T --) {
        string s;
        cin >> s;
        cout << which(s[0]);
    }
    return 0;
}
