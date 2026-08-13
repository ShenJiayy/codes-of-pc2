#include<bits/stdc++.h>
using namespace std;
int n,a[200005],sum;
int main(){
	//freopen("05-05.in","r",stdin);
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sum+=a[i];
	}
	if(n<=2){
		cout<<sum/3;
		return 0;
	}
	bool fl_3=1;
	for(int i=1;i<=n;i++)if(a[i]%3)fl_3=0;
	if(fl_3){
		cout<<sum/3;
		return 0;
	}
	bool fl_4=1;
	for(int i=1;i<=n;i++)if(a[i]!=2)fl_4=0;
	if(fl_4){
		cout<<sum/3;
		return 0;
	}
	cout<<sum/3;
	return 0;
}
