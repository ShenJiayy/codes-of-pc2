#include<bits/stdc++.h>
using namespace std;
int n,s1,s2,last,bj;
string s;
string t;
int main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	cin>>n;
	cin>>s;
	t=s;
	int i=0;
	while(i<n){
		int res1=0,res2=0,bj1=0,last1=0;
		while(s[i]=='J'){
			if(bj1==0) last1=i,bj1=1;
			res1++,i++;
		}
		while(i+1<n&&s[i]=='O'&&s[i+1]=='I') i+=2,res2++;
		if(res1&&res2){
			if(bj==0)last=last1;bj=1;
			s1+=res1;
			s2+=res2;
		}
		else{
			for(int k=1;k<=s2;k++) t[last++]='O',t[last++]='I';
			for(int k=1;k<=s1;k++) t[last++]='J';
			bj=0;
			s1=s2=0;
			if(!(res1||res2))i++;
		}
	//	cout<<last<<' '<<s1<<' '<<s2<<endl; 
	}
	for(int k=1;k<=s2;k++) t[last++]='O',t[last++]='I';
	for(int k=1;k<=s1;k++) t[last++]='J';
	cout<<t;
	return 0;
}
