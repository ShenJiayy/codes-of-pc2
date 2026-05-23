#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5+10;
int a[N];
int n;
signed main(){
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	cin>>n;
	for(int i = 1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);	
	int minn = 1e9;
	int up = 1e9;
	int now = 0;
	for(int i = 1;i<=n-1;i++){
		if(a[i]!=a[i+1]){
			if(abs(n-i-i)<minn){
				minn = abs(n-i-i);
				up = n-i; 
				now = i;
			}
			else if(abs(n-i-i)==minn&&(n-i)<up){
				up = (n-i); 
				now = i;
			}
		}
	}
	cout<<a[now+1]<<" ";
	return 0;
} 
