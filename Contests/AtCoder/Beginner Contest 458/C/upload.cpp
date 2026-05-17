#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5;
char s[N + 5];
signed main() {
	scanf("%s", s + 1);
    int len = strlen(s + 1), cnt = 0;
    for (int i = 1; i <= len; i ++) {
        if (s[i] != 'C') continue;
        // 它的左侧有 i-1 个字符
        // 他的右侧有len-i个字符
        // 首先，中间有个C
        // 其次，两边扩展的个数得是个偶数
        // 啥意思，没啥意思
        // 中间定死了i
        // 枚举一个长度
        // 对于每个长度答案+1
        // bro，加个长度不得了了
        cnt += min(i - 1, len - i);
        // e，样例
        // cerr << min(i - 1, len - i) << "+";
        // 完了，他自己忘了
        cnt ++;
    }
    cout << cnt;
    return 0;
}
