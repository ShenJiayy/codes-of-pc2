#include<bits/stdc++.h>
using namespace std;
int n,k,ans=0x3f3f3f3f,dpj[70000],dpo[70000],dpi[70000],kth[200010],sumo[200010];
string s;
vector<int> J,O,I;
void Impossible(int k){
	cout<<-1;
	exit(k);
}
int main(){
	freopen("jjooii.in","r",stdin);
	freopen("jjooii.out","w",stdout);
	cin>>n>>k;
	cin>>s;
	s="@"+s;
	int cnt=0,lst=0,cc=0;
	for (int i=1;i<=n;i++){
		if (s[i]=='J'){
			J.push_back(i);
			kth[i]=J.size();
		}
		else if (s[i]=='O') {
			O.push_back(i);
			kth[i]=O.size();
			sumo[i]=sumo[i-1]+1;
		}else{
			I.push_back(i);
			kth[i]=I.size();
		}
		sumo[i]=sumo[i-1];
	}
	if (J.size()<k || O.size()<k || I.size()<k) Impossible(0);
	dpj[0]=J[k-1]-J[0]+1-k,dpi[0]=I[k-1]-I[0]+1-k;
	for (int i=k;i<J.size();i++){
		int j=i-k+1;
		int ms=(J[i]-J[i-1])-(J[j]-J[j-1]);
		dpj[j]=dpj[j-1]+ms;
	}
	for (int i=k;i<I.size();i++){
		int j=i-k+1;
		int ms=(I[i]-I[i-1])-(I[j]-I[j-1]);
		dpi[j]=dpi[j-1]+ms;
	}
	for (int i=0;i+k-1<J.size();i++){
		int cnt=0,j,pos=0,pp=0,st=J[i+k-1],ep=0;
		for (j=J[i+k-1]+1;j<=n;j++){
			if (s[j]=='O') cnt++;
			if (cnt>=k) {
				ep=j;
				break;
			}
		}
		if (cnt<k) break;
		pos=*lower_bound(I.begin(),I.end(),ep);
		pp=pos-st-1;
		if (pos==0) break;
		if (kth[pos]+k-1>I.size()) break;
		ans=min(ans,dpj[i]+pp-k+dpi[kth[pos]]);
	}
	if (ans==0x3f3f3f3f) Impossible(0);
	cout<<ans;
	return 0;
}
