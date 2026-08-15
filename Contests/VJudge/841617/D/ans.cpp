#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=410;
int n,m,f[N][N][210][2],ans;//定义状态
struct que
{
	int x,t;
}a[N];//距离和爆炸时间
signed main(){
	cin>>n>>m;//个数和周长
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].x;
		a[i+n+1].x=a[i].x+m;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].t;
		a[i+n+1].t=a[i].t;
	}//破环为链
	memset(f,0x3f,sizeof(f));
	a[n+1].x=m,a[n+1].t=-1e18,f[n+1][n+1][0][0]=0,f[n+1][n+1][0][1]=0;//加入起点
	for(int j=n+1;j<=2*n+1;j++)
	{
		for(int i=n+1;j&&j-i<=n;i--)
		{
			f[i][j][0][0]=m-a[i].x;
			f[i][j][0][1]=a[j].x-m;
		}
	}//初始化
	for(int len=1;len<=n;len++)//从小往大，按顺序
	{
		for(int i=1;i<=n+1;i++)//枚举左端点
		{
			int j=i+len;
			for(int k=1;k<=len;k++)//枚举个数
			{
				int s1;
				f[i][j][k][0]=min(f[i][j][k][0],f[i+1][j][k][0]+a[i+1].x-a[i].x);

				s1=f[i+1][j][k-1][0]+a[i+1].x-a[i].x;
				if(s1<=a[i].t)f[i][j][k][0]=min(f[i][j][k][0],s1);

				f[i][j][k][0]=min(f[i][j][k][0],f[i+1][j][k][1]+a[j].x-a[i].x);

				s1=f[i+1][j][k-1][1]+a[j].x-a[i].x;
				if(s1<=a[i].t)f[i][j][k][0]=min(f[i][j][k][0],s1);

				f[i][j][k][1]=min(f[i][j][k][1],f[i][j-1][k][1]+a[j].x-a[j-1].x);

				s1=f[i][j-1][k-1][1]+a[j].x-a[j-1].x;
				if(s1<=a[j].t)f[i][j][k][1]=min(f[i][j][k][1],s1);

				f[i][j][k][1]=min(f[i][j][k][1],f[i][j-1][k][0]+a[j].x-a[i].x);

				s1=f[i][j-1][k-1][0]+a[j].x-a[i].x;
				if(s1<=a[j].t)f[i][j][k][1]=min(f[i][j][k][1],s1);
                
				if(f[i][j][k][0]<1e15)ans=max(ans,k);
				if(f[i][j][k][1]<1e15)ans=max(ans,k);//判断是否成立
			}//状态转移
		}
	}
	cout<<ans;
	return 0;
}
