// ad
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=5e5+7;
struct node{
	int x,e;
	bool operator < (const node &t)const{
		return x<t.x;
	}
}a[MAXN];
int n,ans;
bool ok[MAXN];
bool type_1;
signed main(){
	freopen("ad.in","r",stdin);
	freopen("ad.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i].x>>a[i].e;
	if(n<=1000) type_1=1;
	if(type_1){
		sort(a+1,a+n+1);
		int pos=0;
		for(int i=1;i<=n;i++){
			if(i==1){
				pos=i;
				ans++;
				ok[i]=1;
				continue;
			}
			bool flag=1;
			for(int j=1;j<i;j++){
				if(ok[j]==1){
					cout<<i<<" "<<j<<endl;
					if(abs(a[i].x-a[j].x)>a[i].e-a[j].e){
						flag=0;
						break;
					}			
				}
			}
			if(flag) pos=i;
			else if(!flag){
				if(abs(a[pos].x-a[i].x)<=a[pos].e-a[i].e)
				ok[i]=1;
				else{
					ans++;
					pos=i;
					for(int j=1;j<i;j++) ok[j]=0;
				}
			}
		}
		cout<<ans<<endl;
		return 0;
	}
	return 0;
}
