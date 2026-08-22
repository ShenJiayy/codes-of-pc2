#include <bits/stdc++.h>
using namespace std;

int t;
int n, a[1000005];

string d(int l, int r, string s, string cz){
    if (l > r){
        stack <char> st;
        for (int i = 0; i < s.size(); i++){
            if (i < s.size() / 2){
                if (i != 0 && st.top() == s[i]) return "-1";
                else st.push(s[i]);
            }else{
                if (st.top() != s[i]) return "-1";
                else st.pop();
            }
        }
        return cz;
    }
    string r1 = d(l + 1, r, s + char(a[l]), cz + 'L');
    string r2 = d(l, r - 1, s + char(a[r]), cz + 'R');
    if (r1 == "-1" && r2 == "-1") return "-1";
    if (r1 != "-1" && r2 != "-1") return min(r1, r2);
    if (r1 != "-1") return r1;
    return r2;
}

void dan_ce(){
    cin >> n;
    for (int i = 0; i < 2 * n; i++) cin >> a[i];
    cout << d(0, 2 * n - 1, "", "") << '\n';
    return ;
}

int main(){
    freopen("palin.in", "r", stdin);
    freopen("palin.out", "w", stdout);
    cin >> t;
    for (int i = 1; i <= t; i++) dan_ce();
    return 0;
}