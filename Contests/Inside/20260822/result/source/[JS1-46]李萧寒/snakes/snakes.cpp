#include<bits/stdc++.h>
using namespace std;
int shang[50005],l[50005],x[50005];
int main(){
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	int t,n;
	cin>>t;
	for(int _=1;_<=t;_++){
		memset(shang,0,sizeof(shang));
		if(_==1){
			cin>>n;
			for(int i=1;i<=n;i++){
				cin>>l[i];
			}
		}
		else{
			int k;
			cin>>k;
			for(int i=1;i<=k;i++){
				int a,b;
				cin>>a>>b;
				l[a]=b;
			}
		}
		for(int i=1;i<=n;i++){
			x[i]=l[i];
		}
		int cnt=1;
		bool flag=false;
		while(cnt<n){
			int mi=INT_MAX,miid,ma=0,maid;
			for(int i=1;i<=n;i++){
				if(x[i]!=-1){
					if(mi>x[i]){
						mi=x[i];
						miid=i;
					}
					if(ma<=x[i]){
						ma=x[i];
						maid=i;
					}
				}
			}
			if(shang[miid]){
				cout<<shang[miid]<<endl;
				flag=true;
				break;
			}
			shang[maid]=n-cnt+1;
			x[maid]-=x[miid];
			x[miid]=-1;
			cnt++;
		}
		if(flag==false){
			cout<<1<<endl;
		}
	}
	return 0;
}
