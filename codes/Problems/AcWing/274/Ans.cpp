#include <iostream>
#include <cstring>
using namespace std;

const int N = 210, M = 1010, INF = 0x3f3f3f3f;

int n, m;
int d[N][N]; //d[i][j] 表示从 i 到 j 的花费
int p[M]; //p[i] 表示第 i 个请求所在的位置
int f[M][N][N]; //f[i][x][y] 表示已经完成了第 i 个请求，三个员工分别在 p[i], x, y 时的最小花费。

int main()
{
    scanf("%d%d", &n, &m);

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            scanf("%d", &d[i][j]);

    for(int i = 1; i <= m; i++) scanf("%d", &p[i]);

    //初始化
    memset(f, 0x3f, sizeof f);
    p[0] = 3;
    f[0][1][2] = 0;

    //dp
    for(int i = 0; i < m; i++)
        for(int x = 1; x <= n; x++)
            for(int y = 1; y <= n; y++)
            {
                int z = p[i], u = p[i + 1];

                if(x == z || x == y || y == z) continue; //同一个位置不能出现两个员工

                //状态转移方程
                f[i + 1][x][y] = min(f[i + 1][x][y], f[i][x][y] + d[z][u]);
                f[i + 1][z][y] = min(f[i + 1][z][y], f[i][x][y] + d[x][u]);
                f[i + 1][x][z] = min(f[i + 1][x][z], f[i][x][y] + d[y][u]);
            }

    //从所有完成请求的方案中取花费最小值
    int res = INF;
    for(int x = 1; x <= n; x++) //枚举完成所有请求时剩下两个员工所在的位置
        for(int y = 1; y <= n; y++)
        {
            int z = p[m];

            if(x == z || x == y || y == z) continue; //同一个位置不能出现两个员工

            res = min(res, f[m][x][y]); //更新最小值
        }
    printf("%d\n", res);

    return 0;
}