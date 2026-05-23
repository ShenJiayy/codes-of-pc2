#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	int n;
	string a;
	cin>>n>>a;
	while(1){
		int f=0;
	for(int i=0;i<n;i++){
		if(i+2<n&&a[i]=='J'&&a[i+1]=='O'&&a[i+2]=='I'){
			a[i]='O';a[i+1]='I';a[i+2]='J';f=1;
		}
	}
	if(f==0){
			cout<<a;
			return 0;
		}
    } 
} 
