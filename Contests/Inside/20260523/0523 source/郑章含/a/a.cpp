#include<bits/stdc++.h>
using namespace std;
int n,aaa[500010],cnt;
char s[500010];
signed main(){
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	cin>>n;
	scanf("%s",s+1);
	aaa[0]=0;
	s[++n]='O';
	for(int i=1;i<=n;i++){
//		if(i==9){
//			printf("%c %c\n",s[i],s[i+1]);
//		}
		if((s[i]=='O')&&((i==n)||(s[i+1]!='I'))){
			aaa[++cnt]=i;
		}
		if((s[i]=='I')&&((i==1)||(s[i-1]!='O'))){
			aaa[++cnt]=i;
		}
	}
	for(int i=1;i<=cnt;i++){
//		printf("<%d>",aaa[i]);
		int cntJ=0,cntOI=0;
		for(int j=aaa[i-1]+1;j<aaa[i];j++){
			if(s[j]=='J'){
				cntJ++;
			}
			if(s[j]=='O'){
				cntOI++;
			}
		}
		for(int j=1;j<=cntOI;j++){
			printf("OI");
		}
		for(int j=1;j<=cntJ;j++){
			printf("J");
		}
		if(aaa[i]!=n){
			printf("%c",s[aaa[i]]);
		}
	}
	return 0;
} 
