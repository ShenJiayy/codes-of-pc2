#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,a[N],maxn;
map<int,int> last;
int main(){
	freopen("stone.in","r",stdin);
	freopen("stone.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i],last[a[i]]=i;
	int i=1,l=1;
	while(i<=n){
		for(i=l;i<=last[a[l]];i++) a[i]=a[l]; 
		l=last[a[l]]+1;
	}
	for(int i=1;i<=n;i++) cout<<a[i]<<endl;
	return 0;
}
