#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
#define int long long
#define debug
const int N = 30;
char s[20];
int c[N + 5][N + 5];
void init() {
    c[0][0] = 1;
	for (int i = 1; i <= N; i ++)
		for (int j = 1; j <= i; j ++)
			c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
}
int query(int n, int m) {
    return c[n + 1][m + 1];
}
signed main() {
    scanf("%s", s);
    int len = strlen(s);
    for (int i = 1; i < len; i ++)
        if (s[i - 1] >= s[i]) {
            cout << 0;
            return 0;
        }
    init();
    int cnt = 0;
    for (int i = 1; i < len; i ++)
        cnt += query(26, i);
    for (int i = 0; i < len; i ++) {
        // char ch = (!i)?'a':a[i-1]+1;
        // while(ch<=a[i]-1){
        //     ans+=c['z'-ch][len-i-1];
        //     ch++;
        // }
        char ch;
        if (i == 0) ch = 'a';
        else ch = s[i - 1] + 1;
        while (ch <= s[i] - 1) {
            cnt += query('z' - ch, len - i - 1);
            ch ++;
        }
    }
    cout << cnt + 1;
    return 0;
}
