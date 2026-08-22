#include<bits/stdc++.h>
using namespace std;
int T;
int n,x,y,len;
struct node{
	int num;
	int id;
}a[100010];
bool cmp(node a1,node a2){
	return a1.num>a2.num||(a1.num==a2.num&&a1.id>a2.id);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("snacks.in","r",stdin);
	freopen("snacks.out","w",stdout);
	cin>>T;
	cin>>n;
	len=n;
	if(n==3){
		for(int i=1;i<=n;i++){
			cin>>a[i].num;
			a[i].id=i;
		}
		sort(a+1,a+1+n,cmp);
		if((a[1].num-a[len].num>a[2].num)||(a[1].num-a[len].num==a[2].num&&a[1].id>a[2].id)){
			cout<<1<<'\n';
		}else{
			cout<<3<<'\n';
		}
		T--;
		while(T--){
			cin>>n;
			for(int i=1;i<=n;i++){
				cin>>x>>y;
				for(int i=1;i<=len;i++){
					if(a[i].id==x){
						a[i].num=y;
						break;
					}
				}
			}
			sort(a+1,a+1+n,cmp);
			if((a[1].num-a[len].num>a[2].num)||(a[1].num-a[len].num==a[2].num&&a[1].id>a[2].id)){
				cout<<1<<'\n';
			}else{
				cout<<3<<'\n';
			}
		}
	}
	
	return 0;
}
