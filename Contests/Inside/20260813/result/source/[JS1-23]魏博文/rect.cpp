#include<bits/stdc++.h>
using namespace std;
const int N=250005;
vector<int>a[N],s[N];
int main(){
	freopen("rect.in","r",stdin);
	freopen("rect.out","w",stdout);
	int n,m;
	cin>>n>>m;
	//cout<<n;
	for(int i=0;i<=m;i++) s[0].push_back(0);
	for(int i=1;i<=n;i++){
		//cout<<"ss";
		a[i].push_back(0);
		s[i].push_back(0);
		for(int j=1;j<=m;j++){
			//cout<<"kkk";
			int x;
			cin>>x;
			//cout<<s[i-1][j];
			int g=s[i][j-1]+s[i-1][j]-s[i-1][j-1]+x-1;
			//cout<<g;
			a[i].push_back(x-1);
			//cout<<"kkkkkkkkkk  ";
			s[i].push_back(g);
			//cout<<"kk";
		}
		//cout<<"ssss";
	}
	//cout<<n;
	long long v=0;
	if(n==1){
		for(int i=1;i<=m;i++){
			if(s[1][i]==0) v++;
		}
		cout<<v*(v+1)/2;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			for(int k=1;k<=i;k++){
				for(int l=1;l<=j;l++){
					if(s[i][j]-s[i][l-1]-s[k-1][j]+s[k-1][l-1]==0){
						v++;
					}
				}
			}
		}
	}
	cout<<v;
}
