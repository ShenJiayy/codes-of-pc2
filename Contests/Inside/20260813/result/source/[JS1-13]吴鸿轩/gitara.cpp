#include<bits/stdc++.h>
using namespace std;
long long n,p,a1[500010],a2[500010],a3[500010],a4[500010],a5[500010],a6[500010],ans;
int cnt1,cnt2,cnt3,cnt4,cnt5,cnt6;
int main(){
	freopen("gitara.in","r",stdin);
	freopen("gitara.out","w",stdout);
	cin>>n>>p;
	while(n--){
		int x,y;
		cin>>x>>y;
		if(x==1){
			int tot=lower_bound(a1+1,a1+1+cnt1,y)-a1;
			if(a1[tot]==y){
				continue;
			}
			ans+=cnt1-tot+2;
			cnt1=tot;
			a1[tot]=y;
		}else if(x==2){
			int tot=lower_bound(a2+1,a2+1+cnt2,y)-a2;
			if(a2[tot]==y){
				continue;
			}
			ans+=cnt2-tot+2;
			cnt2=tot;
			a2[tot]=y;
		}else if(x==3){
			int tot=lower_bound(a3+1,a3+1+cnt3,y)-a3;
			if(a3[tot]==y){
				continue;
			}
			ans+=cnt3-tot+2;
			cnt3=tot;
			a3[tot]=y;
		}else if(x==4){
			int tot=lower_bound(a4+1,a4+1+cnt4,y)-a4;
			if(a4[tot]==y){
				continue;
			}
			ans+=cnt4-tot+2;
			cnt4=tot;
			a4[tot]=y;
		}else if(x==5){
			int tot=lower_bound(a5+1,a5+1+cnt5,y)-a5;
			if(a5[tot]==y){
				continue;
			}
			ans+=cnt5-tot+2;
			cnt5=tot;
			a5[tot]=y;
		}else{
			int tot=lower_bound(a6+1,a6+1+cnt6,y)-a6;
			if(a6[tot]==y){
				continue;
			}
			ans+=cnt6-tot+2;
			cnt6=tot;
			a6[tot]=y;
		}
	}
	cout<<ans<<'\n';
	return 0;
}
