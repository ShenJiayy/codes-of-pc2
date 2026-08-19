#include<bits/stdc++.h>
using namespace std;
bool a[2505][2505],f[2505][2505][2];
int n,m,ans;
void solve(int p,int q){
	int num=1;
	if(!f[p][q][0]){
		int x1=p,y1=q,flag1=0;
		while(!flag1){
			x1++,y1--;
			if(x1==n+1||y1==0){
				flag1=1;
				continue;
			}
			if(!a[x1][y1]){
				flag1=1;
				continue;
			}
			for(int i=x1-1;i>=p;i--){
				if(a[i][y1]){
				 	flag1=1;
				 	for(int j=i+1;j<x1;j++)f[j][p+q-j][0]=0;
				 	break;
				}
			}
			for(int i=y1+1;i<=q;++i){
				if(a[x1][i]){
				 	flag1=1;
				 	for(int j=i-1;j>y1;j--)f[p+q-j][j][0]=0;
				 	continue;
				}
			}
  			if(flag1)continue;
			num++;
			f[x1][y1][0]=1;
		}
	}
	ans=max(ans,num);
	num=1;
	if(!f[p][q][1]){
		int x2=p,y2=q,flag2=0;
		while(!flag2){
			x2++,y2++;
			if(x2==n+1||y2==m+1){
				flag2=1;
				continue;
			}
			if(!a[x2][y2]){
				flag2=1;
				continue;
			}
			for(int i=x2-1;i>=p;i--){
				if(a[i][y2]){
				 	flag2=1;
				 	for(int j=i+1;j<x2;j++)f[j][j-p+q][1]=0;
				 	break;
				}
			}
			for(int i=y2-1;i>=q;i--){
				if(a[x2][i]){
				 	flag2=1;
				 	for(int j=i+1;j<y2;j++)f[j+p-q][j][1]=0;
				 	continue;
				}
			}
			if(flag2)continue;
			num++;
			f[x2][y2][1]=1;
		}
	}
    ans=max(ans,num);
	return;
} 
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)cin>>a[i][j];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j])solve(i,j);
		}
	}
    cout<<ans;
	return 0;
}