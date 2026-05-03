#include <bits/stdc++.h>
using namespace std;
unordered_map<string, string> mp;
string find(string x) {
    if (mp[x] != x)
        mp[x] = find(mp[x]);
    return mp[x];
}
int main() {
	
    string fzf;
    while (1) {
        string s;
        cin >> s;
        if (s == "$") break;
        else if (s[0] == '#') {
            fzf = s.substr(1);
            if (mp.count(fzf) == 0) mp[fzf] = fzf;
        }
        else if (s[0] == '+') mp[s.substr(1)] = mp[fzf];
        else cout << s.substr(1) << " " << find(s.substr(1)) << endl;
    }
	return 0;
}