// snakes
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=1e6+7;
const int INF=0x3f3f3f3f;
struct node{
	int w,id;
};
int t,n,m,x,y,sum,a[MAXN];
bool die[MAXN];
node Min(node u,node v){
	if(u.w==v.w){
		if(u.id<v.id) return u;
		else return v;
	}
	if(u.w<v.w) return u;
	else return v;
}
node Max(node u,node v){
	if(u.w==v.w){
		if(u.id>v.id) return u;
		else return v;
	}
	if(u.w>v.w) return u;
	else return v;
}
signed main(){
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>t>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	while(1){
		int cnt=0;
		node hmin={INF,INF},hmax={-1,-1},mmin={INF,INF};
		for(int i=1;i<=n;i++){
			if(die[i]) continue;
			hmin=Min(hmin,{a[i],i});
			hmax=Max(hmax,{a[i],i});
			cnt++;
		}
		if(cnt<=1||hmin.id==hmax.id) break;
		for(int i=1;i<=n;i++){
			if(die[i]) continue;
			if(i==hmin.id) continue;
			mmin=Min(mmin,{a[i],i});
		}
		if(Min({hmax.w-hmin.w,hmax.id},mmin).id==mmin.id){
			die[hmin.id]=1;
			a[hmax.id]-=hmin.w;
		}
		else break;
	}
	for(int i=1;i<=n;i++){
		if(die[i]) continue;
		sum++;
	}
	cout<<sum<<endl;
	t--;
	while(t--){
		sum=0;
		memset(die,0,sizeof(die));
		cin>>m;
		for(int i=1;i<=m;i++){
			cin>>x>>y;
			a[x]=y;
		}
		while(1){
		    int cnt=0;
		    node hmin={INF,INF},hmax={-1,-1},mmin={INF,INF};
		    for(int i=1;i<=n;i++){
			    if(die[i]) continue;
			   hmin=Min(hmin,{a[i],i});
			    hmax=Max(hmax,{a[i],i});
		    	cnt++;
		    }
		    if(cnt<=1) break;
		    for(int i=1;i<=n;i++){
			    if(die[i]) continue;
			    if(i==hmin.id) continue;
			    mmin=Min(mmin,{a[i],i});
		    }
		    if(Min({hmax.w-hmin.w,hmax.id},mmin).id==mmin.id){
			    die[hmin.id]=1;
			    a[hmax.id]-=hmin.w;
		    }
		    else break;
    	}
	    for(int i=1;i<=n;i++){
		    if(die[i]) continue;
		    sum++;
	    }
	    cout<<sum<<endl;
	}
	return 0;
}
