/**
我常常追忆过去。

生命瞬间定格在脑海。我将背后的时间裁剪、折叠、蜷曲，揉捻成天上朵朵白云。

云朵之间亦有分别：积云厚重，而卷云飘渺。生命里震撼的场景掠过我的思绪便一生无法忘怀，而更为普通平常的记忆在时间的冲刷下只留下些许残骸。追忆宛如入梦，太过清楚则无法愉悦自己的幻想，过分模糊却又坠入虚无。只有薄雾间的山水，面纱下的女子，那恰到好处的朦胧，才能满足我对美的苛求。

追忆总在不经意间将我裹进泛黄的纸页里。分别又重聚的朋友，推倒又重建的街道，种种线索协助着我从一个具体的时刻出发沿时间的河逆流而上。曾经的日子无法重来，我只不过是一个过客。但我仍然渴望在每一次追忆之旅中留下闲暇时间，在一个场景前驻足，在岁月的朦胧里瞭望过去的自己，感受尽可能多的甜蜜。美好的时光曾流过我的身体，我便心满意足。

过去已经凝固，我带着回忆向前，只是时常疏于保管，回忆也在改变着各自的形态。这给我的追忆旅程带来些许挑战。

我该在哪里停留？我问我自己。
*　　┏┓　　　┏┓+ +
*　┏┛┻━━━┛┻┓ + +
*　┃　　　　　　　┃
*　┃　　　━　　　┃ ++ + + +
*  ████━████+
*  ◥██◤　◥██◤ +
*　┃　　　┻　　　┃
*　┃　　　　　　　┃ + +
*　┗━┓　　　┏━┛
*　　　┃　　　┃ + + + +Code is far away from 　
*　　　┃　　　┃ + bug with the animal protecting
*　　　┃　 　 ┗━━━┓ 神兽保佑,代码无bug　
*　　　┃ 　　　　　　 ┣┓
*　　  ┃ 　　　　　 　┏┛
*　    ┗┓┓┏━┳┓┏┛ + + + +
*　　　　┃┫┫　┃┫┫
*　　　　┗┻┛　┗┻┛+ + + +
*/
#include<bits/stdc++.h>
#define I return
#define AK 0
#define IOI
#define ll long long
using namespace std;
ll n,a[5010],b[5010],id[5010],cnt,mx[5010][5010],se[5010][5010],p[5010],dp[5010][5010];
vector<ll> g[5010];
void dfs(int x,int f){
	id[x]=++cnt;
	for(auto v:g[x]){
		if(v==f) continue;
		dfs(v,x);
	}
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("cat.in","r",stdin);
    freopen("cat.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>b[i];
	}
	int top=0;
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		g[v].push_back(u);
		g[u].push_back(v);
	}
	for(int i=1;i<=n;i++){
		if(g[i].size()==1){
			top=i;
			break;
		}
	}
	dfs(top,0);
	for(int i=1;i<=n;i++){
		a[id[i]]=b[i];
		mx[0][id[i]]=i;
	}
	for(int i=1;i<=n;i++){
		p[a[i]]=i;
		//cout<<a[i]<<" ";
	}
	for(int i=1;i<=n;i++){
		se[i][i]=-114514;
		mx[i][i]=a[i];
		for(int j=i+1;j<=n;j++){
			if(a[j]>mx[i][j-1]){
				mx[i][j]=a[j];
				se[i][j]=mx[i][j-1];
			}
			else if(a[j]<mx[i][j-1]&&a[j]>se[i][j-1]){
				mx[i][j]=mx[i][j-1];
				se[i][j]=a[j];
			} 
			else{
				mx[i][j]=mx[i][j-1];
				se[i][j]=se[i][j-1];
			}
		}
	}
	for(int len=2;len<=n;len++){
		for(int l=1;l+len-1<=n;l++){
			int r=l+len-1,ma=mx[l][r],sc=se[l][r];
			if(p[sc]<p[ma]) dp[l][r]=max(dp[l][p[ma]-1]+p[ma]-p[sc],dp[p[sc]+1][r]);
			else dp[l][r]=max(dp[p[ma]+1][r]+p[sc]-p[ma],dp[l][p[ma]-1]);
			//cout<<l<<" "<<r<<" "<<ma<<" "<<sc<<" "<<dp[l][r]<<"\n";
		}
	}
	cout<<dp[1][n];
    I AK IOI;
}
