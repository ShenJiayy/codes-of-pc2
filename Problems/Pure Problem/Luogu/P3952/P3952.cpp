#include <bits/stdc++.h>
using namespace std;
#define int long long
const int VOID = -9e18;
const int N = 100;
short status[N + 5];
bool vis[128];
int GetPow(string s) {
    if (s == "O(1)") return 0;
    int sum = 0;
    char a = s[4], b = s[5];
    if (b == ')') return a - '0';
    int num = (a - '0') * 10 + b - '0';
    return num;
}
signed main() {
    #ifndef ONLINE_JUDGE
        freopen("in.in", "r", stdin);
    #endif
    int T;
    cin >> T;
    while (T --) {
        memset(vis, 0, sizeof vis);
        memset(status, 0, sizeof status);
        int l;
        cin >> l;
        string OTime;
        cin >> OTime;
        int wantedPow = GetPow(OTime);
        stack<char> vars;
        stack<int> ids;
        bool ERR = 0;
        int sum = 0, brokencnt = 0, ans = 0;
        for (int i = 1; i <= l; i ++) {
            char op;
            cin >> op;
            if (op == 'F') {
                char var;
                cin >> var;
                if (vis[var]) {
                    ERR = 1;
                    // continue;
                }
                vis[var] = 1;
                string xx, yy;
                int x, y;
                cin >> xx >> yy;
                if (xx == "n") x = 1e9;
                else x = stoll(xx);
                if (yy == "n") y = 1e9;
                else y = stoll(yy);
                if (x > y)
                    brokencnt ++, status[i] = -1;
                else if (xx != "n" && yy == "n") {
                    sum ++, status[i] = 1;
                    if (brokencnt == 0)
                        ans = max(ans, sum);
                }
                ids.push(i);
                vars.push(var);
            }
            else {
                if (vars.empty()) {
                    ERR = 1;
                    // continue;
                }
                if (brokencnt == 0)
                    ans = max(ans, sum);
                vis[vars.top()] = 0;
                vars.pop();
                int topid = ids.top();
                ids.pop();
                if (status[topid] == 1)
                    sum --;
                else if (status[topid] == -1)
                    brokencnt --;
            }
        }
        if (!vars.empty())
            ERR = 1;
        if (ERR)
            cout << "ERR\n";
        else if (ans == wantedPow)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}