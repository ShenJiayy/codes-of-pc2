#include<bits/stdc++.h>
using namespace std;
using ll=long long;

ll n,q,fun,m=998244353,a[400005],tre[400005],addtag[400005],multag[400005];

void pushup(ll p){
	tre[p]=tre[p*2]+tre[p*2+1]; //错误：写成了 tre[p]=tre[p*2]=tre[p*2+1] 
}

void build(ll p,ll l,ll r){
	if(l==r){
		tre[p]=a[l];
		return;
	}
	int mid=(l+r)/2;
	build(p*2,l,mid);
	build(p*2+1,mid+1,r);
	pushup(p);
}

void pushdown(ll p,ll l,ll r){
	if(addtag[p]!=0||multag[p]!=1){
//		multag[p*2]*=multag[p];
//		multag[p*2]%=m; 
//		addtag[p*2]*=multag[p];
//		addtag[p*2]%=m;
//		addtag[p*2]+=addtag[p];
//		addtag[p*2]%=m;
//		tre[p*2]=tre[p*2]*multag[p*2]+addtag[p*2];
//		tre[p*2]%=m;
//		
//		multag[p*2+1]*=multag[p];
//		multag[p*2+1]%=m; 
//		addtag[p*2+1]*=multag[p];
//		addtag[p*2+1]%=m;
//		addtag[p*2+1]+=addtag[p];
//		addtag[p*2+1]%=m;
//		tre[p*2+1]=tre[p*2+1]*multag[p*2+1]+addtag[p*2+1];
//		tre[p*2+1]%=m;
		
		int mid=(l+r)/2;
		
		multag[p*2]=multag[p*2]*multag[p]%m;
		addtag[p*2]=(addtag[p*2]*multag[p]+addtag[p])%m; //*multag[p]写成+multag[p] ,%m写成%p 
		tre[p*2]=(tre[p*2]*multag[p]+addtag[p]*(mid-l+1))%m;
		
		multag[p*2+1]=multag[p*2+1]*multag[p]%m;
		addtag[p*2+1]=(addtag[p*2+1]*multag[p]+addtag[p])%m; //*multag[p]写成+multag[p] ,%m写成%p
		tre[p*2+1]=(tre[p*2+1]*multag[p]+addtag[p]*(r-mid))%m;
		
		multag[p]=1,addtag[p]=0;
	}
}

void updadd(ll p,ll l,ll r,ll ql,ll qr,ll val){
	if(ql<=l&&r<=qr){ //原错误条件：l<=ql&&qr<=r,updadd,updmul,query全写错了 
		addtag[p]+=val;
		addtag[p]%=m;
		tre[p]+=(r-l+1)*val;
		tre[p]%=m; 
		return;
	}
	
	pushdown(p,l,r);
	int mid=(l+r)/2;
	if(ql<=mid) updadd(p*2,l,mid,ql,qr,val);
	if(mid+1<=qr) updadd(p*2+1,mid+1,r,ql,qr,val);
	pushup(p);
}

void updmul(ll p,ll l,ll r,ll ql,ll qr,ll val){
	if(ql<=l&&r<=qr){
		multag[p]=multag[p]*val%m;
		addtag[p]=addtag[p]*val%m;
		tre[p]=tre[p]*val%m;
		return;
	}
	
	pushdown(p,l,r);
	int mid=(l+r)/2;
	if(ql<=mid) updmul(p*2,l,mid,ql,qr,val);
	if(mid+1<=qr) updmul(p*2+1,mid+1,r,ql,qr,val);
	pushup(p);
}

ll query(ll p,ll l,ll r,ll ql,ll qr){
	if(ql<=l&&r<=qr){
		return tre[p];
	}
	
	pushdown(p,l,r);
	int mid=(l+r)/2;
	ll res=0;
	if(ql<=mid) res+=query(p*2,l,mid,ql,qr);
	if(mid+1<=qr) res+=query(p*2+1,mid+1,r,ql,qr);
	res%=m;
	return res;
}

void debug1(){
	for(int i=1;i<=4*n;++i) cout<<tre[i]<<" ";
	cout<<'\n';
}
void debug2(){
	for(int i=1;i<=4*n;++i) cout<<multag[i]<<" ";
	cout<<'\n';
}
void debug3(){
	for(int i=1;i<=4*n;++i) cout<<addtag[i]<<" ";
	cout<<'\n';
}

vector<ll> type[1000005];

void diaoyong(ll kkk){
    if(type[kkk][0]==1){
        updadd(1,1,n,type[kkk][1],type[kkk][1],type[kkk][2]);
        return;
    }
    if(type[kkk][0]==2){
        updmul(1,1,n,1,n,type[kkk][1]);
        return;
    }
    if(type[kkk][0]==3){
        for(int i=1;i<=(int)type[kkk].size()-1;++i){
            diaoyong(type[kkk][i]);
        }
    }
}
int main(){
    freopen("call.in","r",stdin);
    freopen("call.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
    fill(multag+1,multag+4*n+1,1);
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    build(1,1,n);
    cin>>fun;
    for(int i=1;i<=fun;++i){
        ll tj;
        cin>>tj;
        type[i].emplace_back(tj);
        if(tj==1){
            ll ak,b;
            cin>>ak>>b;
            type[i].emplace_back(ak);
            type[i].emplace_back(b);
        }
        if(tj==2){
            ll ak;
            cin>>ak;
            type[i].emplace_back(ak);
        }
        if(tj==3){
            ll cj;
            cin>>cj;
            for(int j=1;j<=cj;++j){
                ll b;
                cin>>b;
                type[i].emplace_back(b);
            }
        }
    }

    cin>>q;
    for(int i=1;i<=q;++i){
        ll ak;
        cin>>ak;
        diaoyong(ak);
        
    }

    for(int i=1;i<=n;++i){
        cout<<query(1,1,n,i,i)<<" ";
    }
    return 0;
}

