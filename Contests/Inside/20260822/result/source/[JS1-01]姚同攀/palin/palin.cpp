#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int T,n,a[N];
string ansL,ansR;
bool work(int L,int R,int l,int r){
	for(int i=2;i<=n;++i){
		if(L<l&&a[L]==a[l]){
			++L,--l;
			ansL=ansL+"L";
			ansR="L"+ansR;
		}else if(L<=l&&r<=R&&a[L]==a[r]){
			++L,++r;
			ansL=ansL+"L";
			ansR="R"+ansR;
		}else if(L<=l&&r<=R&&a[l]==a[R]){
			--l,--R;
			ansL=ansL+"R";
			ansR="L"+ansR;
		}else if(r<R&&a[r]==a[R]){
			++r,--R;
			ansL=ansL+"R";
			ansR="R"+ansR;
		}else return false;
	}
	return true;
}
void solve(){
	scanf("%d",&n);
	int n2=n+n;
	for(int i=1;i<=n2;++i) scanf("%d",&a[i]);
	ansL="L";
	ansR="L";
	for(int i=2;i<=n2;++i)
		if(a[i]==a[1]){
			if(work(2,n2,i-1,i+1)){
				cout<<ansL<<ansR<<"\n";
				return;
			}
			break;	
		}
	ansL="R";
	ansR="L";
	for(int i=2;i<=n2;++i)
		if(a[i]==a[n2]){
			if(work(1,n2-1,i-1,i+1)){
				cout<<ansL<<ansR<<"\n";
				return;
			}
			break;	
		}
	printf("-1\n");
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}

/*
1
20
17 3 16 1 9 12 19 6 8 2 20 14 18 10 5 11 15 7 13 4 4 13 7 15 11 5 10 18 17 14 20 2 8 6 19 12 9 1 16 3

RRRRRRRRRRRRRRRRRRRR
RRRRRRRRLRRRRRRRRRRL
*/
