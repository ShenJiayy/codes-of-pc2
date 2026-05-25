#include <cstdio>
#include <cstring>
using namespace std;
int n, r, data[20];
bool app[20];
void print() {
    for (int i = 0; i < r - 1; i ++) printf("%d", data[i] + 1);
    printf("%d\n", data[r - 1] + 1);
}
void done(int i) {
    if (i == r) {
        print();
        return;
    }
    for (int j = 0; j < n; j ++)
        if (!app[j]) {
            app[j] = 1;
            data[i] = j;
            done(i + 1);
            app[j] = 0;
        }
}
int main() {
    memset(app, 0, sizeof app);
    scanf("%d%d", &n, &r);
    done(0);
}