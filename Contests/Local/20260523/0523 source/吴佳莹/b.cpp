#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,a[N];
int main()
{
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+1+n);
	int x=(1+n)/2;
	for(int i=x+1;i<=n;i++){
		if(a[i]!=a[i-1]){
			cout<<a[i];
			return 0;
		}
	}
	return 0;
}
