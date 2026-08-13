#include<bits/stdc++.h>
using namespace std;
const int MAX=300001;
int a[MAX],c[MAX],d[MAX];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("d.in","r",stdin);
	freopen("d.out","w",stdout);
	int n,q;
	cin>>n>>q;
	long long ma=0;
	for(int i=1;i<=n;i++) {cin>>a[i];ma+=a[i];}
	for(int i=1;i<=q;i++) cin>>c[i]>>d[i];
	sort(a+1,a+1+n,cmp);
	//cout<<last<<endl;
	for(int j=1;j<=q;j++){
		long long ans=0,last=ma;
		int k=1;
		while(1){
			ans=0;
			for(int i=1;i<=n;i++){
			    ans+=max(0,a[i]-(k*d[j]));
			    //cout<<" "<<max(0,a[i]-(k*d[j]))<<" ";
			}
			if(ans+(k*c[j])<last){
				last=ans+(k*c[j]);
				//cout<<ans<<" "<<last<<" "<<k*c[j]<<endl;
				k++;
			}
			else{
				//cout<<ans<<" "<<last<<" "<<k*c[j]<<endl;
				cout<<last<<endl;
				break;
			}
		}
	}
} 
