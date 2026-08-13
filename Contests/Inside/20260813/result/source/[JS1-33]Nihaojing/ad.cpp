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
ll n,tim,ans;
struct nd{
	ll e,x,id;
}a[500010],b[500010],c[500010];
bool vis[500010];
bool cmp1(nd x,nd y){
	if(x.e!=y.e) return x.e>y.e;
	return x.id<y.id;
}
bool cmp2(nd x,nd y){
	if(x.e-x.x!=y.e-y.x) return x.e-x.x<y.e-y.x;
	else if(x.e!=y.e) return x.e<y.e;
	return x.id>y.id;
}
bool cmp3(nd x,nd y){
	if(x.e+x.x!=y.e+y.x) return x.e+x.x<y.e+y.x;
	else if(x.e!=y.e) return x.e<y.e;
	return x.id>y.id;
}
map<int,bool> f;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("ad.in","r",stdin);
    freopen("ad.out","w",stdout);
    cin>>n;
    if(n*n<=5e7){
	    for(int i=1;i<=n;i++){
	    	cin>>a[i].x>>a[i].e;
	    	a[i].id=i;
	    	b[i]=c[i]=a[i];
		}
		sort(a+1,a+n+1,cmp1);
		sort(b+1,b+n+1,cmp2);
		sort(c+1,c+n+1,cmp3);
		for(int i=1;i<=n;i++){
			int x=a[i].id;
			if(vis[x]) continue;
			vis[x]=1;
			ans++;
			for(int j=1;j<=n;j++){
				if(b[j].id==x) break;
				if(b[j].x>a[i].x) continue;
				vis[b[j].id]=1;
				tim+=2;
			}
			for(int j=1;j<=n;j++){
				if(c[j].id==x) break;
				if(c[j].x<a[i].x) continue;
				vis[c[j].id]=1;
				tim+=2;
			}
		}
		cout<<ans;
	}
	int cnt=0;
    for(int i=1;i<=n;i++){
    	int x,e;
    	cin>>x>>e;
    	if(!f[x]) cnt++;
    	f[x]=1;
	}
	cout<<cnt;
    I AK IOI;
}
