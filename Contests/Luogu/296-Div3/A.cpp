#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, s;
    cin >> n >> s;
    int t = s;
    for (int i = 1; i <= n; i ++) {
    	string opt;
    	cin >> opt;
    	if (opt.find("kirai") != string::npos) {
    		if (t >= 0)
    			t = 0;
    	}
    	else if (opt.find("daishuki") != string::npos)
    		t += 2;
    	else if (opt.find("shuki") != string::npos)
    		t ++;
    	else t --;
	}
	if (t > 0)
		cout << t - s;
	else puts("shuki");
}
