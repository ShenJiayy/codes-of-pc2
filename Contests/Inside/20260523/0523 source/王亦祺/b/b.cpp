#include<iostream>
#include<algorithm>
#include<math.h>
#include<fstream>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	int n,arr[500005]={},link[500005],cnt[500005]={},sum[500005]={};
	cin>>n;
	for(int i=1;i<=n;i++) cin>>arr[i];
	sort(&arr[1],&arr[n+1]);
	int now=0;
	for(int i=1;i<=n;i++){
		if(arr[i]!=arr[i-1]){
			now++;
			link[now]=arr[i];
		}
		cnt[now]++;
	}
	int ans=now;
	for(int i=now;i>=1;i--) sum[i]=sum[i+1]+cnt[i];
	for(int i=now-1;i>=now/2;i--){
		if(abs(2*sum[i]-n)<abs(2*sum[i+1]-n)) ans=i;
	}
	cout<<link[ans];
	return 0;
}
