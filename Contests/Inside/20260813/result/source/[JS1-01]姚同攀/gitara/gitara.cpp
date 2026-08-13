#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,p,Q[10][N],ans,len[10];
int main(){
	freopen("gitara.in","r",stdin);
	freopen("gitara.out","w",stdout);
	scanf("%d%d",&n,&p);
	while(n--){
		int a,b;
		scanf("%d%d",&a,&b);
		while(Q[a][len[a]]>b) --len[a],++ans;
		if(Q[a][len[a]]==b) continue;
		Q[a][++len[a]]=b,++ans;
//		printf("%d\n",ans);
	}
	printf("%d",ans);
	return 0;
} 
