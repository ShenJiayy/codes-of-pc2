#include<bits/stdc++.h>
using namespace std;
int n;
string s;
string stk;
string func(string s){
	for(int i=0;i<n;++i){
		while(1){
			if(i<=n-3&&s[i]=='J'&&s[i+1]=='O'&&s[i+2]=='I'){
				s[i]='O',s[i+1]='I',s[i+2]='J';
			}
			else if(i<=n-2&&s[i-1]=='J'&&s[i]=='O'&&s[i+1]=='I'){
				s[i-1]='O',s[i]='I',s[i+1]='J';
			}
			else if(i<=n-1&&s[i-2]=='J'&&s[i-1]=='O'&&s[i]=='I'){
				s[i-2]='O',s[i-1]='I',s[i]='J';
			}
			else{
				break;
			}
		}
	}
	return s;
}
int main(){
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	//freopen("04-08.in","r",stdin);
	cin>>n>>s;
	/*
	对于i=0,1,...,n-1，执行如下操作：
	如果 i<=n-3 且 s[i..i+2]="JOI"，则直接令s[i..i+2]="OIJ"
	     i<=n-2 且 s[i-1..i+1]="JOI"， 则直接令s[i-1..i+1]="OIJ"
	     i<=n-1 且 s[i-2..i]="JOI"， 则直接令s[i-2..i]="OIJ"
	样例验证（JOIJOI）：
	i=0,s[0..2]="JOI",s="OIJJOI"
	i=1,s[1..3]="IJJ",s="OIJJOI"
	i=2,s[2..4]="JJO",s="OIJJOI"
	i=3,s[3..5]="JOI",s="OIJOIJ",s[2..4]="JOI",s="OIOIJJ"
	i=4,i=5
	answer= OIOIJJ
	
	JJJOIOIO
	i=0,JJJOIOIO
	i=1,JJJOIOIO
	i=2,JJOIJOIO,JOIJJOIO,OIJJJOIO
	i=3,OIJJJOIO
	i=4,OIJJOIJO,OIJOIJJO,OIOIJJJO
	*/
	if(n<=100){
		while(s!=func(s)) s=func(s);
	}
	else{
		s=func(s);
	}
	cout<<s;
	return 0;
} 
