// 数据生成文件
// 用法：
// rand.exe [Nmax] [LenMax] [datafile] [seed]
#include <bits/stdc++.h>
using namespace std;
int main(int argc, char** argv) {
    mt19937 rnd(atoi(argv[4]));
	freopen(argv[3], "w", stdout);
	int n = rnd() % atoi(argv[1]) + 1;
    cout << n << endl;
    for (int i = 1; i <= n + 1; i ++)
        cout << rnd() % atoi(argv[2]) + 1 << " ";
    cout << endl;
    for (int i = 1; i <= n; i ++)
        cout << rnd() % atoi(argv[2]) + 1 << " ";
    fclose(stdout);
	return 0;
}
