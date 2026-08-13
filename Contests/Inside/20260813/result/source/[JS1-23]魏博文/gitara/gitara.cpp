#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int s[10][N],v[10];
int main(){
	freopen("gitara.in","r",stdin);
	freopen("gitara.out","w",stdout);
	int n,p;
	long long ans=0;
	cin>>n>>p;
	for(int i=1;i<=n;i++){
		int a,b;
		cin>>a>>b;
		while(s[a][v[a]]>b){
			v[a]--;
			ans++;
		}
		if(s[a][v[a]]<b){
			ans++;
			v[a]++;
			s[a][v[a]]=b;
		}
	}
	cout<<ans;
}
