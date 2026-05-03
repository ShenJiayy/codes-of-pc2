#include <bits/stdc++.h>
using namespace std;
int main() {
	system("g++ upload.cpp -std=c++98 -O2 -o ttttt");
    for (int i = 0; i < 110; i ++)
        for (int j = 0; j < 110; j ++)
            for (int k = 0; k < 110; k ++)
                if (i + j + k) {
                    freopen("data.in", "w", stderr);
                    cerr << i << " " << j << " " << k;
                    cerr << "\n0 0 0";
                    fclose(stderr);
                    int ret = system("ttttt < data.in > data.out");
                    if (ret) {
                        cout << i << " " << j << " " << k << endl;
                        system("pause");
                    }
                    else cout << "Not RTE.\n";
                }
}
