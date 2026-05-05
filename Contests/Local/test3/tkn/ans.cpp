#include <cstdio>
int b[31], n, k;
int main() {
    b[0] = 0;
    for (int i = 1, j = 1; i <= 30; i ++, j *= 2)
        b[i] = b[i - 1] + j;
    scanf("%d%d", &n, &k);
    int total = 0, rest = n;
    for (int sum = 0; sum < k + n / 2; sum ++, rest += k) {
        for (int i = 1; i <= 30; i ++)
            if (b[i] > rest) {
                rest -= b[i - 1];
                total += i - 1;
                break;
            }
        if (!rest) break;
    }
    if (rest) printf("ERROR");
    else printf("OK %d", total);
    return 0;
}