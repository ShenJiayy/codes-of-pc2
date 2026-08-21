#include<bits/stdc++.h>
using namespace std;
const int maxn=22,maxm=1e5+5;
int f[1<<maxn];
int num[maxn],sum[maxm][maxn];
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        int aa;
        scanf("%d",&aa);
        num[aa]++;
        for(int j=1;j<=m;j++) sum[i][j]=sum[i-1][j];
        sum[i][aa]++;
    }
    memset(f,0x3f,sizeof(f));
    f[0]=0;
    for(int i=1;i<(1<<m);i++){
        int len=0;
        for(int j=1;j<=m;j++){
            if(i&(1<<(j-1))) len+=num[j];
        }
        for(int j=1;j<=m;j++){
            if(i&(1<<(j-1))) 
                f[i]=min(
                    f[i],
                        f[i^(1<<(j-1))] + num[j] - sum[len][j] + 
                        sum[len-num[j]][j]);
        }
    }
    printf("%d\n",f[(1<< m)-1]);
    return 0;
}
