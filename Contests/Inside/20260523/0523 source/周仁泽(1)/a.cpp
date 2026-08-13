#include <bits/stdc++.h>
using namespace std;
int n,r=-1;
string s,k;
int main(){
	freopen("a.in","w",stdin);
	freopen("a.out","r",stdout);
	cin>>n;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]=='J'){
			k+='J';
		} 
		else if(s[i]=='q') continue;
		else if(s[i]=='O'){
			if(i<s.size()-1&&s[i+1]=='I'){
				k+='K';
				s[i+1]='q';
			}
			else{
				k+='O';
			}
		}
		else if(s[i]=='I'){
			k+='I';
		}
	}
	for(int i=0;i<k.size();i++){
		if(k[i]=='J'){
			if(r==-1) r=i;
		}
		else if(k[i]=='K'){
			if(r!=-1){	
				k[i]='J';
				k[r]='K';
				r+=1;
			}
		}
		else r=-1;
	}
	for(int i=0;i<k.size();i++){
		if(k[i]!='K') cout<<k[i];
		else cout<<"OI";
	}
	cout<<endl;
	return 0;
}
