#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,k,J[N],O[N],I[N],ans=1e9;
int kJ[N],kO[N],kI[N];
string s;
int main(){
	freopen("jjooii.in","r",stdin);
	freopen("jjooii.out","w",stdout);
	scanf("%d%d",&n,&k);
	cin>>s;
	for(int i=0;i<s.size();++i){
		J[i+1]=J[i]+(s[i]=='J');
		O[i+1]=O[i]+(s[i]=='O');
		I[i+1]=I[i]+(s[i]=='I');
	}
	for(int r=1,l=1;r<=n;++r)
		while(J[r]-J[l-1]==k){
			kJ[l]=r;
			++l;
		}
	for(int r=1,l=1;r<=n;++r)
		while(O[r]-O[l-1]==k){
			kO[l]=r;
			++l;
		}
	for(int r=1,l=1;r<=n;++r)
		while(I[r]-I[l-1]==k){
			kI[l]=r;
			++l;
		}
	for(int i=1;i<=n;++i){
		int p=kI[kO[kJ[i]]];
		if(!p) break;
		ans=min(ans,p-i+1);
	}
	ans==1e9?printf("-1"):printf("%d",ans-k*3);
	return 0;
}
