#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
const int N = 100;
int d[N + 5];
int main(int argc, char** argv){
	registerTestlibCmd(argc, argv);
	int T = inf.readInt();
	for (int cs = 1; cs <= T; cs ++) {
		printf("Testing Case %d: ", cs);
		int n = inf.readInt();
		for (int i = 1; i <= n; i ++)
			d[i] = inf.readInt();
		
		// string ansf = ans.readString();
		// string outf = ouf.readString();
		// if (ansf != outf) {
		// 	printf("Error: Diffrence on 1st line.\n");
		// 	quitf(_wa, "Diffrence on 1st line.");
		// }
		// if (ansf == "NO") {
		// 	printf("OK\n");
		// 	continue;
		// }
		// for (int i = 1; i <= n; i ++)
		// 	for (int j = 1; j <= m; j ++) {
		// 		int x = ouf.readInt();
		// 		if (!(0 <= x && x <= 100)) {
		// 			printf("Error: Output data(s[%d][%d]) out of range.\n", i, j);
		// 			quitf(_wa, "Error: Output data(s[%d][%d]) out of range.\n", i, j);
		// 		}
		// 		s[i][j] = x;
		// 		x = ans.readInt();
		// 		if (!(0 <= x && x <= 100)) {
		// 			printf("Error: Answer data out of range.\n");
		// 			quitf(_fail, "Answer data out of range.");
		// 		}
		// 		ans.skipBlanks();
		// 		ouf.skipBlanks();
		// 	}
		// for (int i = 1; i <= n; i ++)
		// 	for (int j = 1; j <= n; j ++) {
		// 		if (i == j) continue;
		// 		bool happy = 0;
		// 		for (int k = 1; k <= m; k ++)
		// 			if (s[i][k] > s[j][k])
		// 				happy = 1;
		// 		if (happy != a[i][j]) {
		// 			printf("Error: Your output data disobey the rule.\n");
		// 			quitp(0.5, "Your output data disobey the rule.");
		// 		} 
		// 	}
		printf("OK\n");
	}
	while (!ouf.seekEof())
		ouf.readToken();
	while (!inf.seekEof())
		inf.readToken();
	while (!ans.seekEof())
		ans.readToken();
	quitf(_ok, "No difference found, congratulations!");
	return 0;
}