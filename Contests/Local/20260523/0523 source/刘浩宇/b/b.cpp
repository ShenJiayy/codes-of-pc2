#include<bits/stdc++.h>
using namespace std;
int n;
long long a[500005];
int main(){
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		int j=i;
		while(a[j]==a[i]){
			j++;
		}
		i=j;
		if(i>=n-i){
			while(a[j]==a[i]){
				j--;
			}
			int temp=i;
			while(a[temp]==a[i]){
				i++;
			}
			i--;
			if(n%2==0){
				if((n/2)-j<=i-(n/2)){
					cout<<a[j+1];
					return 0;
				}
				cout<<a[i+1];
				return 0;
			}
			else{
				if((n/2+1)-j<=i-(n/2+1)){
					cout<<a[j];
					return 0;
				}
				cout<<a[i+1];
				return 0;
			}
		}
	}
	return 0;
}
