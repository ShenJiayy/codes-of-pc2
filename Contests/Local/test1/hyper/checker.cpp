#include "testlib.h"
#include <string>
#include <cctype>
#include <stack>
#include <set>
#include <cmath>
using namespace std;
const set<int> base = {1,2,3,5,7};
long long calc(const string &s, int &pos, bool &valid) {
    int n = s.size();
    long long res = 0;
    if (s[pos] == '(') {
        pos++;
        long long a = calc(s, pos, valid);
        if (!valid) return 0;
        char op = s[pos];
        if (op != '+' && op != '*' && op != '-') {
            valid = false;
            return 0;
        }
        pos++;
        long long b = calc(s, pos, valid);
        if (!valid) return 0;
        if (s[pos] != ')') {
            valid = false;
            return 0;
        }
        pos++;
        if (op == '+') res = a + b;
        else if (op == '*') res = a * b;
        else if (op == '-') res = a - b;
        if (pos < n && s[pos] == '!') {
            pos++;
            if (res < 0 || res > 20) {
                valid = false;
                return 0;
            }
            long long f = 1;
            for (int i=2; i<=res; i++) f *= i;
            res = f;
        }
        return res;
    }
    if (!isdigit(s[pos])) {
        valid = false;
        return 0;
    }
    int num = 0;
    while (pos < n && isdigit(s[pos])) {
        num = num * 10 + s[pos] - '0';
        pos++;
    }
    if (!base.count(num)) {
        valid = false;
        return 0;
    }
    res = num;
    if (pos < n && s[pos] == '!') {
        pos++;
        if (res < 0 || res > 20) {
            valid = false;
            return 0;
        }
        long long f = 1;
        for (int i=2; i<=res; i++) f *= i;
        res = f;
    }
    return res;
}
int count_digits(const string &s, int &pos) {
    int cnt = 0;
    int n = s.size();
    while (pos < n) {
        if (s[pos] == '(') {
            pos++;
            cnt += count_digits(s, pos);
            pos++; // op
            cnt += count_digits(s, pos);
            pos++; // )
            if (pos < n && s[pos] == '!') pos++;
            return cnt;
        }
        if (isdigit(s[pos])) {
            cnt++;
            while (pos < n && isdigit(s[pos])) pos++;
            if (pos < n && s[pos] == '!') pos++;
            return cnt;
        }
        pos++;
    }
    return cnt;
}
int main(int argc, char *argv[]) {
    registerTestlibCmd(argc, argv);
    int n = inf.readInt();
    string user = ouf.readToken();
    string jury = ans.readToken();
    int pos = 0;
    bool valid = true;
    long long val = calc(user, pos, valid);
    if (pos != (int)user.size()) valid = false;
    if (!valid) {
        quitf(_wa, "Format Error");
    }
    if (val != n) {
        quitf(_wa, "Answer Not Correct, Want %d, Except %lld", n, val);
    }
    pos = 0;
    int user_cnt = count_digits(user, pos);
    pos = 0;
    bool dummy = true;
    calc(jury, pos, dummy);
    pos = 0;
    int jury_cnt = count_digits(jury, pos);
    if (user_cnt > jury_cnt) {
        quitf(_wa, "Number Count Not Least, Want %d, Except %d", jury_cnt, user_cnt);
    }
    quitf(_ok, "Answer Correct");
    return 0;
}