#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5;

signed main() {
	freopen("stone.in", "r", stdin);
	freopen("stone.out", "w", stdout);
	int T;
    cin >> T;
    if (T <= 2000) {
        vector<int> v;
        while (T --) {
            int x;
            cin >> x;
            int pos = 0;
            for (int i = 0; i < v.size(); i ++)
                if (v[i] == x)
                    pos = i;
            for (int i = pos; i < v.size(); i ++)
                v[i] = x;
            v.push_back(x);
        }
        for (int val : v)
            cout << val << endl;
    }
    else {
        vector<int> v;
        while (T --) {
            int x;
            cin >> x;
            v.push_back(x);
        }
        if (v.back() == 2) {
            int p = 0;
            for (int i = 0; i < v.size(); i ++)
                if (v[i] == 1)
                    p = i;
            for (int i = 0; i <= p; i ++)
                cout << 1 << endl;
            for (int i = p + 1; i < v.size(); i ++)
                cout << 2 << endl;
        }
        if (v.back() == 1) {
            int p = 0;
            for (int i = 0; i < v.size(); i ++)
                if (v[i] == 2)
                    p = i;
            for (int i = 0; i <= p; i ++)
                cout << 2 << endl;
            for (int i = p + 1; i < v.size(); i ++)
                cout << 1 << endl;
        }
    }
	return 0;
}
