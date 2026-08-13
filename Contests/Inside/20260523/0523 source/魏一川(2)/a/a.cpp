#include<bits/stdc++.h>
using namespace std;
int n;
string s;
int main(){
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	cin>>n>>s;
	if(n%3==0){
		bool fl_2=1;
		for(int i=0;i<n;i+=3){
			if(s[i]!='J'||s[i+1]!='O'||s[i+2]!='I'){
				fl_2=0;
				break;
			}
		}
		if(fl_2){
			for(int i=1;i<=n/3;i++)cout<<"OI";
			for(int i=1;i<=n/3;i++)cout<<'J';
		}
		return 0;
	}
	bool fl=1;
	while(fl){
		fl=0;
		for(int i=0;i<n;i++){
			if(s[i]=='J'&&s[i+1]=='O'&&s[i+2]=='I'){
				s[i]='O';
				s[i+1]='I';
				s[i+2]='J';
				i+=2;
				fl=1;
			}
		}
	}
	cout<<s;
	return 0;
}
