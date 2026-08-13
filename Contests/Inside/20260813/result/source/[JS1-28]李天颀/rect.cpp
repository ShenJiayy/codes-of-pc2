#include <bits/stdc++.h>
using namespace std;
int n,m,ans;
int main(){
	freopen("rect.in","r",stdin);
	freopen("rect.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	if(n==1){
		int arr[250010]={0};
		for(int i=1;i<=m;i++) cin>>arr[i];
		for(int l=1;l<=m;l++){
			int sum = 0;
			for(int i=1;i<=l;i++) sum += arr[i];
			if(sum==l) ans++;
			for(int i=2;i<=m-l+1;i++){
				sum += arr[i+l-1];
				sum -= arr[i-1];
				if(sum==l) ans++;
			}
		}
	}
	else if(n<=30&&m<=30){
		int arr[35][35]={0};
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>arr[i][j]; 
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				for(int p=i;p<=n;p++){
					for(int q=j;q<=m;q++){
						int sum = 0;
						for(int w=i;w<=p;w++){
							for(int e=j;e<=q;e++){
								sum += arr[w][e];
							}
						}
						if(sum==(p-i+1)*(q-j+1)) ans++;
					}
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
