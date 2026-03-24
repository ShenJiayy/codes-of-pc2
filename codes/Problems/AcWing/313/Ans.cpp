#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N=110;
int w[N][N];
int f[N][N];//前i朵花，放在了前j个花瓶里的最大值
int p[N][N];
int n,m;
void print(int i,int j)
{
    if(i==0||j==0)return ;
    while(f[i][j]==f[i][j-1])j--;
    print(i-1,j-1);
    cout<<j<<" ";
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>w[i][j];
    for(int i=1;i<=n;i++)
        for(int j=i;j<=m;j++)
            if(j==i)f[i][j]=f[i-1][j-1]+w[i][j];
            else f[i][j]=max(f[i][j-1],f[i-1][j-1]+w[i][j]);
    cout<<f[n][m]<<endl;
    print(n,m);
}