#include<bits/stdc++.h>
using namespace std;
int n,J,OI;
string s;
int main(){
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	scanf("%d",&n);
	cin>>s;
	int i;
	for(i=0;i<n-1;++i){
		if(s[i]=='J') ++J;
		else if(s[i]=='O'&&s[i+1]=='I') ++OI,++i;
		else{
			while(OI--) printf("OI");
			while(J--) printf("J");
			OI=J=0;
			printf("%c",s[i]);
		}
		
	}
	while(OI--) printf("OI");
	while(J--) printf("J");
	if(i<n) printf("%c",s[n-1]);
	return 0;
} 
