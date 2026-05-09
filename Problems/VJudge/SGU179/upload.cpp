#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6;
bool vis[N + 5];
char s[N + 5];
int p[N + 5];
signed main() {
    scanf("%s", s + 1);
    int len = strlen(s + 1);
    for (int i = 1; i <= len; i ++)
        vis[i] = s[i] == ')';
    for (int i = 1; i <= len; i ++)
        if (vis[i] == 0) p[i] = p[i - 1] + 1;
        else p[i] = p[i - 1] - 1;
    bool no = 1;
    for (int i = 1; i <= len; i += 2) 
        no &= (vis[i] == 0 && vis[i + 1] == 1);
    if (no) {
        puts("No solution");
        return 0;
    }
    int l0;
    for (int i = len; i >= 1; i --)
        if (vis[i] == 0) {
            l0 = i;
            break;
        }
    if (l0 != len - 1) {
        int l1;
        for (int i = l0; i <= len; i ++)
            if (vis[i] == 1) {
                l1 = i;
                break;
            }
        if (l0 == len - 1) {
            puts("No solution");
            return 0;
        }
        swap(s[l0], s[l1]);
        puts(s + 1);
        return 0;
    }
    int lid = -1;
    for (int i = l0 - 1; i >= 1; i --)
        if (vis[i] == 1 && vis[i - 1] == 0 && p[i - 1] >= 1) {
            lid = i;
            break;
        }
    if (lid == -1) {
        puts("No solution");
        return 0;
    }
    swap(s[lid], s[lid - 1]);
    int bkl = len - lid;
    for (int i = lid + 1; i <= bkl / 2 + lid; i ++)
        s[i] = '(';
    for (int i = lid + bkl / 2 + 1; i <= len; i ++)
        s[i] = ')';
    puts(s + 1);
    return 0;
}