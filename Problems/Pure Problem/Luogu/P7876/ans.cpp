#include<bits/stdc++.h>
using namespace std;
int read(){
    int x=0,f=1;char ch=getchar();
    while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
    while(isdigit(ch)){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return x*f;
}
int t,T,n,m,tot,f=1;
int a[110][110],vis[110],rk[110],fa[110],cnt[110],root[110],ans[110][110]; 
vector<int> g[110];//记录各个块内的人员 
int get(int x){return (x==fa[x]?x:(fa[x]=get(fa[x])));}
void Union(int x,int y){fa[get(x)]=get(y);}
int main(){
	t=read();T=read();
	while(T--){
		memset(rk,0,sizeof(rk));//每个人在自己的块内的排名 
		memset(vis,0,sizeof(vis));  //计算排名时，记录该排名是否有人 
		memset(cnt,0,sizeof(cnt));  //每个块内的人数 
		tot=0;						//块的个数 
		f=1;						//是否有解 
		n=read();m=read();
		for(int i=1;i<=n;i++)while(g[i].size())g[i].pop_back();
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				a[i][j]=read();
		for(int k=1;k<=n;k++)
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++){
					if(i==j||j==k||k==i)continue;
					if(a[i][k]==0&&a[k][j]==0&&a[i][j]!=0)
						f=0;
				} 
		for(int i=1;i<=n;i++)fa[i]=i;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(i!=j&&!a[i][j])
					Union(i,j);//处理块 
		for(int i=1;i<=n;i++)g[get(i)].push_back(i);
		for(int x=1;x<=n;x++)
			if(g[x].size()){
				memset(vis,0,sizeof(vis));
				++tot;
				cnt[x]=g[x].size();
				for(int i=0;i<g[x].size();i++)
					for(int j=0;j<g[x].size();j++){
						int t1=g[x][i],t2=g[x][j];
						if(t1!=t2&&a[t1][t2]==0)rk[t1]++; 
					} 
				for(int i=0;i<g[x].size();i++){
					if(vis[rk[g[x][i]]])f=0;
					vis[rk[g[x][i]]]=1;
					if(rk[g[x][i]]==0)root[x]=g[x][i];
				}//判定无解 
			}
		if(f==0||(m==1&&tot!=1)){printf("NO\n");continue;}
		int sum=0;
		for(int i=1;i<=n;i++)if(cnt[i]){
			ans[root[i]][1]=sum+cnt[i];
			ans[root[i]][2]=100-sum;
			for(int j=3;j<=m;j++)ans[root[i]][j]=100;
			for(int j=0;j<g[i].size();j++){
				int tmp=g[i][j];
				for(int k=1;k<=m;k++)
					ans[tmp][k]=ans[root[i]][k]-rk[tmp];
			}
			sum=sum+cnt[i];//记录已处理的人数，确定下一块最高分前两门学科的分数 
		}
		printf("YES\n");
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++)
				printf("%d ",ans[i][j]);
			printf("\n");
		}
	}
	return 0;
}
