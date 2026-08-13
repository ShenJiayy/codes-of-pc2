#include<bits/stdc++.h>
using namespace std;
int n,m,a[101][101],b[101][101],ans;
int main(){
    freopen("rect.in","r",stdin);
	freopen("rect.out","w",stdout);
    cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
            if(a[i][j]==1){
                ans++;
            }
			b[i][j]=b[i-1][j]+b[i][j-1]-b[i-1][j-1]+a[i][j];
            //cout<<b[i][j]<<" ";
		}
        //cout<<endl;
	}
	for(int li=1;li<=n;li++){
		for(int lj=1;lj<=m;lj++){
            if(li==1&&lj==1){
                continue;
            }
			for(int i=1;i+li-1<=n;i++){
				for(int j=1;j+lj-1<=m;j++){
                    //cout<<b[i+li-1][j+lj-1]+b[i-1][j-1]-b[i+li-1][j-1]-b[i-1][j+lj-1]<<endl;
					if((b[i+li-1][j+lj-1]+b[i-1][j-1]-b[i+li-1][j-1]-b[i-1][j+lj-1])==li*lj){
						ans++;
					}
				}
			}
		}
	}
	cout<<ans<<'\n';
	return 0;
}
