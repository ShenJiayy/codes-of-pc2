#include<bits/stdc++.h>
using namespace std;
int a[11],s[11];
int main(){
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	int t,n;
	cin>>t;
	for(int i=1;i<=t;i++){
		if(i==1){
			cin>>n;
			for(int j=1;j<=n;j++){
				cin>>a[j];
				s[j]=a[j];
				//cout<<s[j]<<" "<<j<<" ddd";
			}
		}
		else{
			int k;
			cin>>k;
			for(int j=1;j<=k;j++){
				int x,y;
				cin>>x>>y;
				a[x]=y;
			}
			for(int j=1;j<=n;j++){
				s[j]=a[j];
			}
		}
		//cout<<s[1]<<" "<<s[2]<<" "<<s[3]<<"kkk";
		sort(s+1,s+1+n);
		//cout<<s[1]<<" "<<s[2]<<" "<<s[3]<<"dzd";
		if(n==3){
			if(s[3]>s[2]+s[1]||(s[3]==s[2]+s[2]&&s[3]==a[3])){
				cout<<"1\n";
			}
			else cout<<"3\n";
		}
	}
}
