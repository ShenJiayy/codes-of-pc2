#include<iostream>
#include<cstring>
#include<fstream>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	int n;
	string s;
	cin>>n>>s;
	if(n<=100){
		for(int i=1;i<=n;i++){
			for(int i=3;i<=n;i++){
				if(s[i-3]=='J'&&s[i-2]=='O'&&s[i-1]=='I'){
					s[i-3]='O';
					s[i-2]='I';
					s[i-1]='J';
				}
			}
		}
		cout<<s;
		return 0;
	}
	else{
		for(int i=1;i<=n/3;i++) cout<<"OI";
		for(int i=1;i<=n/3;i++) cout<<"J";
		return 0;
	}
	return 0;
}
