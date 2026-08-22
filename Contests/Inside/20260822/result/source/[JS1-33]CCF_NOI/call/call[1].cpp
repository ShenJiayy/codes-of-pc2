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
ll n,m,a[100010],P=998244353;
struct fuc{
	ll x,y;
}b[100010];
vector<ll> g[100010];
vector<pair<ll,ll>> f[100010];
struct nd{
	ll l,r,sum,tg;
}tr[400010];
void bul(int l,int r,int p){
	if(l==r){
		tr[p]={l,r,a[l],1};
		return ;
	}
	int mid=(l+r)/2;
	bul(l,mid,p*2);
	bul(mid+1,r,p*2+1);
	tr[p]={l,r,(tr[p*2].sum+tr[p*2+1].sum)%P,1};
}
void upd(int x,int p,ll k){
	int l=tr[p].l,r=tr[p].r;
	if(l==x&&r==x){
		tr[p].sum=(tr[p].sum+k)%P;
		return ;
	} 
	if(l>x||r<x) return ;
	tr[p*2].sum=(tr[p*2].sum*tr[p].tg)%P;
	tr[p*2].tg=(tr[p*2].tg*tr[p].tg)%P;
	tr[p*2+1].sum=(tr[p*2+1].sum*tr[p].tg)%P;
	tr[p*2+1].tg=(tr[p*2+1].tg*tr[p].tg)%P;
	tr[p].tg=1;
	upd(x,p*2,k);
	upd(x,p*2+1,k);
	tr[p].sum=(tr[p*2].sum+tr[p*2+1].sum)%P;
}
ll qry(int x,int p){
	int l=tr[p].l,r=tr[p].r;
	if(l==x&&r==x) return tr[p].sum;
	if(l>x||r<x) I AK IOI;
	tr[p*2].sum=(tr[p*2].sum*tr[p].tg)%P;
	tr[p*2].tg=(tr[p*2].tg*tr[p].tg)%P;
	tr[p*2+1].sum=(tr[p*2+1].sum*tr[p].tg)%P;
	tr[p*2+1].tg=(tr[p*2+1].tg*tr[p].tg)%P;
	tr[p].tg=1;
	return (qry(x,p*2)+qry(x,p*2+1))%P;
}
void sol(int x){
	if(b[x].x&&b[x].y) upd(b[x].x,1,b[x].y);
	if(!b[x].x&&b[x].y) tr[1].tg=(tr[1].tg*b[x].y)%P;
	else{
		for(auto v:g[x]){
			sol(v);
		}
	}
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("call.in","r",stdin);
    freopen("call.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	cin>>m;
	for(int i=1;i<=m;i++){
		int op;
		cin>>op;
		if(op==1){
			int x,y;
			cin>>x>>y;
			b[i]={x,y};
		}
		if(op==2){
			int x;
			cin>>x;
			b[i]={0,x};
		}
		if(op==3){
			int k;
			cin>>k;
			for(int j=1;j<=k;j++){
				int x;
				cin>>x;
				g[i].push_back(x);
			}
		}
	}
	bul(1,n,1);
	int Q;
	cin>>Q;
	while(Q--){
		int x;
		cin>>x;
		sol(x);
	}
	for(int i=1;i<=n;i++){
		cout<<qry(i,1)<<" ";
	}
    I AK IOI;
}
//fc C:\Users\Administrator\Desktop\std\call\call.out C:\Users\Administrator\Desktop\std\call\call3.ans
