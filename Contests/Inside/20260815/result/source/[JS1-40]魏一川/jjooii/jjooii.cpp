#include<bits/stdc++.h>
using namespace std;
int n,k,cnt_O,cnt_I,ans=INT_MAX;
string s;
int main(){
	freopen("jjooii.in","r",stdin);
	freopen("jjooii.out","w",stdout);
	scanf("%d%d",&n,&k);
	cin>>s;
	s=" "+s;
	vector<int>J,O,I;
	for(int i=1;i<=n;i++){
		if(s[i]=='J')J.push_back(i);
		if(s[i]=='O')O.push_back(i);
		if(s[i]=='I')I.push_back(i);
	}
	for(int i=0;i<J.size()-k+1;i++){
		while(cnt_O<O.size()-k+1&&O[cnt_O]<J[i+k-1])cnt_O++;
		while(cnt_I<I.size()-k+1&&I[cnt_I]<O[i+k-1])cnt_I++;
		if(O[cnt_O]<=J[i]||I[cnt_I]<=J[i])break;
		cout<<J[i]<<' '<<O[cnt_O]<<' '<<I[cnt_I]<<"\n";
		int sum=0;
		for(int j=0;j<i;j++)sum+=(J[i+j]-J[i+j-1]-1)+(O[i+j]-O[cnt_O+j-1]-1)+(I[i+j]-I[cnt_I+j-1]-1);
		ans=min(ans,sum);
	}
	cout<<(ans==INT_MAX?-1:ans);
	return 0;
}
