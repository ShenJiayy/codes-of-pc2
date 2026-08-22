#include<bits/stdc++.h>
using namespace std;
const int N=2005;
struct node{
	int val,id;
};
int T,n;
node num[N],num1[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	cin>>T;
	for(int yy=1;yy<=T;yy++){
		
		int ans=0;
		if(yy==1){cin>>n;
		for(int i=1;i<=n;i++){
			cin>>num[i].val;
			num[i].id=i;
		}
		}else{
			int k;
			cin>>k;
		//	cout<<k<<"ereve";
			for(int i=1;i<=k;i++){
				int xx,yy;
				cin>>xx>>yy;
				num[xx].val=yy;
			//	cout<<yy<<" ";
			}
		}
		sort(num+1,num+n+1,[](node &u,node &v){
			if(u.val==v.val)return u.id<v.id;
			return u.val<v.val;
		});
		for(int i=1;i<=n;i++)num1[i].val=num[i].val,num1[i].id=num[i].id;
	//	cout<<"\n";
		int chs=n;
		while(num1[chs].val-num1[1].val>num1[2].val||((num1[chs].val-num1[1].val==num1[2].val)&&num1[chs].id>num1[2].id)||(chs==2)){
			if(chs==1)break;
			num1[1].val=num1[chs].val-num1[1].val;
			num1[1].id=num1[chs].id;
			chs--;
			sort(num1+1,num1+chs+1,[](node &u,node &v){
			if(u.val==v.val)return u.id<v.id;
			return u.val<v.val;
		});
	//	cout<<"ueriofrofjcerofj";
	//	for(int i=1;i<=chs;++i)cout<<num1[i].val<<" "<<num1[i].id<<"\n";
		}
		//if(num1[chs].val-num1[1].val>num1[2].val||((num1[chs].val-num1[1].val==num1[2].val)&&num1[chs].id>num1[2].id)||(chs==2))chs--;
		//cout<<num1[chs].val<<" "<<num1[2].val <<" "<<num1[1].val<<"\n";
		cout<<chs<<"\n";
	}
	return 0;
}
