#include<bits/stdc++.h>
using namespace std;
int n,k,ans=2e9;
int J[200005],O[200005],I[200005];
int jj,oo,ii;
string ss;
int main(){
	freopen("jjooii.in","r",stdin);
	freopen("jjooii.out","w",stdout);
	scanf("%d%d",&n,&k);
	cin>>ss;
	for(int i=0;i<n;i++){
		if(ss[i]=='J')J[++jj]=i;
		else if(ss[i]=='O') O[++oo]=i;
		else if(ss[i]=='I') I[++ii]=i;
	}
	int lso=1,lsi=1;
	for(int i=1;i<=jj;i++){
		if(i+k-1>jj) break;
		int end=J[i+k-1];
		while(lso<=oo&&O[lso]<=end) lso++;
		if(lso+k-1>oo) break;
		end=O[lso+k-1];
		while(lsi<=ii&&I[lsi]<=end) lsi++;
		if(lsi+k-1>ii) break;
		ans=min(ans,I[lsi+k-1]-J[i]+1-3*k); 
	}
	if(ans==2000000000) printf("-1"); 
	else printf("%d",ans);
	return 0;
}
