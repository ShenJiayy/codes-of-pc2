#include <iostream>
#include <cstdio>
using namespace std;
char s[600000];
int main(){
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	int n;
	cin>>n;
	scanf("%c",&s[0]);
	for(int i=0;i<n;i++)scanf("%c",&s[i]);
	int k=-1;
	for(int i=0;i<n-1;i++){
	//	cout<<i<<' '<<k<<' ';
		if(s[i]=='O'&&s[i+1]=='I'){
			if(k!=-1){
				s[i]=s[i+1]='J';
				s[k]='O';
				s[k+1]='I';
				k+=2;
			}
		}
		if(k==-1&&s[i]=='J')k=i;
		if(s[i]!='J')k=-1;
		
	}
	for(int i=0;i<n;i++)printf("%c",s[i]);
	return 0;
} 
