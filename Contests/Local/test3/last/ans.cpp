#include <vector>
# include <cstring>
#include <cstdio>
using namespace std;
const int maxn = 30000;
bool temp[maxn+ 1];
vector<int> prime,fac;//fac表示各个因子出现的次数
int rst[10];//rst 数组保存运算结果
void Add(int x, int t){
    for (int i=0;i< prime.size()&& prime[i]<=x;i++)
        while (!(x % prime[i])){
            x/=prime[i];
            fac[i]+=t;
        }
}
int main() {
    memset(temp, true,sizeof(temp));
    prime.clear();
    fac.clear();
    for (int i=2;i<=maxn;i++)
        if (temp[i]){
            prime.push_back(i);
            fac. push_back(0);
            for(int j=i*i;j<=maxn;j+=i)temp[j]= false;
        }
    int n, r;
    scanf("%d%d",&n,&r);
    if(r>n-r)r=n-r;
    for(int i=0;i<r;i++){
        Add(n-i, 1);//将n-r+1~n的因子加到fac中
        Add(i+1,-1);//将1~r的因子从fac中减去
    }
    memset(rst, 0, sizeof (rst));//将1~r的因子从a数组中减去
    rst[0]=1;
    for (int i=0; i< prime.size();i++)
        for(int j=0;j<fac[i];j++){
            for (int k=0;k<10;k++)rst[k]*=prime[i];
            for (int k=0;k<10;k++){
                if (k<9)rst[k+1]+=rst[k]/10;
                rst[k]%=10;
            }
        }
    for (int i=9;i>=0;i--) printf("%d",rst[i]);
    printf("\n");
    return 0;
}