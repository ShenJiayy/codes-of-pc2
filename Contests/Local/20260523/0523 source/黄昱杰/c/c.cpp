#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
bool fl;
char a[500005];
signed main(){
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	do{
		fl=0;
		for(int i=1;i<=n-2;i++){
			if(a[i]=='J'&&a[i+1]=='O'&&a[i+2]=='I'){
			a[i]='O',a[i+1]='I',a[i+2]='J';
			fl=1;
			//for(int j=1;j<=n;j++)cout<<a[i];
	}
			
	 }
	} 
	while(fl==1);
	
	for(int i=1;i<=n;i++)cout<<a[i];
	return 0;
} 
