#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,t;
bool fg=1,fl;
char a[500005],b[500005];
signed main(){
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!='J')fg=0;
		if(fg!=0)t++;
	}
	if(t>100){
		if(a[t+1]=='O'){
		int s=0;char y='O';
		for(int i=t+1;i<=n;i++){
			
			if(y!=a[i])break;
			char x=a[i];
			b[++s]=x;
			if(x=='O')y='I';
			if(x=='I')y='O';
			
		}
			if(b[s]=='O'){
				for(int i=1;i<=s-1;i++)cout<<b[i];
				for(int i=1;i<=t;i++)cout<<'J';
				for(int i=s+t;i<=n;i++)cout<<a[i];
			}
			if(b[s]=='I'){
				for(int i=1;i<=s;i++)cout<<b[i];
				for(int i=1;i<=t;i++)cout<<'J';
				for(int i=s+t;i<=n;i++)cout<<a[i];
			}
	}
	else{
		for(int i=1;i<=n;i++)cout<<a[i];
	}
	}else{
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
	
		
		
		
	
	return 0;
}

