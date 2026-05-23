#include<bits/stdc++.h>
using namespace std;
int a[200001];//s[200001];
int main(){
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	int n;
	long long ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
	    cin>>a[i];ans+=a[i]/3;a[i]=a[i]%3;//    s[i]=s[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		if(a[i]==1&&a[i+1]==1&&a[i+2]==1){
			a[i]=0;a[i+1]=0;a[i+2]=0;ans++;
		}
		else if(a[i]==1&&a[i+1]==1&&a[i+2]==0){
			a[i]=1;a[i+1]=1;a[i+2]=0;
		}
		else if(a[i]==1&&a[i+1]==1&&a[i+2]==2){
			a[i]=0;a[i+1]=0;a[i+2]=1;ans++;
		}
		else if(a[i]==1&&a[i+1]==0&&a[i+2]==1){
			a[i]=1;a[i+1]=0;a[i+2]=1;
		}
		else if(a[i]==1&&a[i+1]==0&&a[i+2]==2){
			a[i]=1;a[i+1]=0;a[i+2]=2;
		}
		else if(a[i]==1&&a[i+1]==0&&a[i+2]==0){
			a[i]=1;a[i+1]=0;a[i+2]=0;
		}
		else if(a[i]==1&&a[i+1]==2&&a[i+2]==0){
			a[i]=0;a[i+1]=0;a[i+2]=0;ans++;
		}
		else if(a[i]==1&&a[i+1]==2&&a[i+2]==1){
			a[i]=0;a[i+1]=0;a[i+2]=1;ans++;
		}
		else if(a[i]==1&&a[i+1]==2&&a[i+2]==2){
			a[i]=0;a[i+1]=1;a[i+2]=1;ans++;
		}//1
		else if(a[i]==2&&a[i+1]==1&&a[i+2]==1){
			a[i]=0;a[i+1]=0;a[i+2]=1;ans++;
		}
		else if(a[i]==2&&a[i+1]==1&&a[i+2]==0){
			a[i]=0;a[i+1]=0;a[i+2]=0;ans++;
		}
		else if(a[i]==2&&a[i+1]==1&&a[i+2]==2){
			a[i]=0;a[i+1]=0;a[i+2]=2;ans++;
		}
		else if(a[i]==2&&a[i+1]==0&&a[i+2]==1){
			a[i]=2;a[i+1]=0;a[i+2]=1;
		}
		else if(a[i]==2&&a[i+1]==0&&a[i+2]==2){
			a[i]=2;a[i+1]=0;a[i+2]=2;
		}
		else if(a[i]==2&&a[i+1]==0&&a[i+2]==0){
			a[i]=2;a[i+1]=0;a[i+2]=0;
		}
		else if(a[i]==2&&a[i+1]==2&&a[i+2]==0){
			a[i]=0;a[i+1]=1;a[i+2]=0;ans+=1;
		}
		else if(a[i]==2&&a[i+1]==2&&a[i+2]==1){
			a[i]=0;a[i+1]=1;a[i+2]=1;ans+=1;
		}
		else if(a[i]==2&&a[i+1]==2&&a[i+2]==2){
			a[i]=0;a[i+1]=0;a[i+2]=0;ans+=2;
		}//2
		if(a[i]==0&&a[i+1]==1&&a[i+2]==1){
			a[i]=0;a[i+1]=1;a[i+2]=1;
		}
		else if(a[i]==0&&a[i+1]==1&&a[i+2]==0){
			a[i]=0;a[i+1]=1;a[i+2]=0;
		}
		else if(a[i]==0&&a[i+1]==1&&a[i+2]==2){
			a[i]=0;a[i+1]=0;a[i+2]=0;ans++;
		}
		else if(a[i]==0&&a[i+1]==0&&a[i+2]==1){
			a[i]=0;a[i+1]=0;a[i+2]=1;
		}
		else if(a[i]==0&&a[i+1]==0&&a[i+2]==2){
			a[i]=0;a[i+1]=0;a[i+2]=2;
		}
		else if(a[i]==0&&a[i+1]==0&&a[i+2]==0){
			a[i]=0;a[i+1]=0;a[i+2]=0;
		}
		else if(a[i]==0&&a[i+1]==2&&a[i+2]==0){
			a[i]=0;a[i+1]=2;a[i+2]=0;
		}
		else if(a[i]==0&&a[i+1]==2&&a[i+2]==1){
			a[i]=0;a[i+1]=0;a[i+2]=0;ans++;
		}
		else if(a[i]==0&&a[i+1]==2&&a[i+2]==2){
			a[i]=0;a[i+1]=0;a[i+2]=1;ans++;
		}//0
	}
	cout<<ans;
} 
