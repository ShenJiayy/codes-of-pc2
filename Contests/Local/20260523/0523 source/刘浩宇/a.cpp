#include<bits/stdc++.h>
using namespace std;
int n;
string s;
bool check(){
	for(int i=1;i<=n-2;i++){
		if(s[i]=='J'&&s[i+1]=='O'&&s[i+2]=='I'){
			return 0;
		}
	}
	return 1;
}
int main(){
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	if(n>100){
		if(s[1]=='J'&&s[2]=='J'){
			int k=1;
			while(s[k]=='J'){
				k++;
			}
			for(int i=k;i<=n-2;i+=2){
				if(s[i+1]!='O'||s[i+2]!='I'){
					break;
				}
				s[i]='O';
				s[i+1]='I';
				s[i+2]='J';
			}
		}
		else{
			for(int i=2;i<=n/3*2;i+=2){
				s[i-1]='O';
				s[i]='I';
			}
			for(int i=n/3*2+1;i<=n;i++){
				s[i]='J';
			}
		}
	}
	else{
		while(!check()){
			for(int i=1;i<=n-2;i++){
				if(s[i]=='J'&&s[i+1]=='O'&&s[i+2]=='I'){
					s[i]='O';
					s[i+1]='I';
					s[i+2]='J';
				}
			}
		} 
	}
	for(int i=1;i<=n;i++){
		cout<<s[i];
	}
	return 0;
} 
