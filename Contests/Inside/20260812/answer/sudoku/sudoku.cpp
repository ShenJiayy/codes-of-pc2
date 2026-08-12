#include <bits/stdc++.h>
using namespace std;
#define int long long
char c[15][15];
int a[10][10];
const int d[] = {2, 3, 4, 6, 7, 8, 10, 11, 12};

#define no return
#define solution puts("GRESKA"),
#define thanks 0;

signed main() {
    freopen("sudoku.in", "r", stdin);
    freopen("sudoku.out", "w", stdout);
    for (int i = 1; i <= 13; i ++)
        for (int j = 1; j <= 13; j ++)
            cin >> c[i][j];
    for (int i = 0; i < 9; i ++)
        for (int j = 0; j < 9; j ++)
            if (c[d[i]][d[j]] != '.')
                a[i + 1][j + 1] = c[d[i]][d[j]] - '0';
    // 行
    set<int> st;
    int cnt;
    for (int i = 1; i <= 9; i ++) {
        st.clear();
        cnt = 0;
        for (int j = 1; j <= 9; j ++)
            if (a[i][j])
                st.insert(a[i][j]), cnt ++;
        if (st.size() < cnt)
            no solution thanks
    }
    // 列
    for (int j = 1; j <= 9; j ++) {
        st.clear();
        cnt = 0;
        for (int i = 1; i <= 9; i ++)
            if (a[i][j])
                st.insert(a[i][j]), cnt ++;
        if (st.size() < cnt)
            no solution thanks
    }
    // 宫
    for (int dx = 1; dx <= 7; dx += 3)
        for (int dy = 1; dy <= 7; dy += 3) {
            st.clear();
            cnt = 0;
            for (int i = dx; i < dx + 3; i ++)
                for (int j = dy; j < dy + 3; j ++)
                    if (a[i][j])
                        st.insert(a[i][j]), cnt ++;
            if (st.size() < cnt)
                no solution thanks
        }
    return puts("OK"), 0;
}