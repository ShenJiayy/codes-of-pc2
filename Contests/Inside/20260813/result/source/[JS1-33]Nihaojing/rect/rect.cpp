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
const int N=2750010;
int n,m;
ll ans,cnt[N*2];
vector<int> a[250010],sum[250010];
int main(){
    freopen("rect.in","r",stdin);
    freopen("rect.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
    	a[i].push_back(0);
    	for(int j=1;j<=m;j++){
    		int x;
    		scanf("%d",&x);
    		a[i].push_back(x-1);
		}
	}
	for(int i=1;i<=m;i++){
		sum[0].push_back(0);
	}
	for(int i=1;i<=n;i++){
		sum[i].push_back(0);
		for(int j=1;j<=m;j++){
			sum[i].push_back(sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+a[i][j]);
			//cout<<sum[i][j]<<" ";
		}
		//cout<<"\n";
	}
    if(n>m){
		for(int x1=1;x1<=m;x1++){
			for(int x2=0;x2<x1;x2++){
				for(int x=0;x<=n;x++){
					ans+=cnt[sum[x][x1]-sum[x][x2]+N];
					cnt[sum[x][x1]-sum[x][x2]+N]++;
				}
				for(int x=0;x<=n;x++){
					cnt[sum[x][x1]-sum[x][x2]+N]--;
				}
			}
		}
	} 
	else{
		for(int x1=1;x1<=n;x1++){
			for(int x2=0;x2<x1;x2++){
				for(int x=0;x<=m;x++){
					ans+=cnt[sum[x1][x]-sum[x2][x]+N];
					cnt[sum[x1][x]-sum[x2][x]+N]++;
				}
				for(int x=0;x<=m;x++){
					cnt[sum[x1][x]-sum[x2][x]+N]--;
				}
			}
		}
	} 
	printf("%lld",ans);
    I AK IOI;
}
//fc C:\Users\Administrator\Desktop\Nihaojing\rect\rect.out C:\Users\Administrator\Desktop\Nihaojing\rect\rect1.out 
