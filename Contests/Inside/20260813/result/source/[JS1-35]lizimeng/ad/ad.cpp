#include<bits/stdc++.h>
using namespace std;
int ans,xyl[500010],pos[500010],n;
int rd[500010];
bool isSame=true;
int main(){
	freopen("ad.in","r",stdin);
	freopen("ad.out","w",stdout);
	cin.tie(0),cout.tie(0),ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>pos[i]>>xyl[i];
		if(i!=1&&xyl[i]!=xyl[i-1]) isSame=false;
	}
	if(isSame){
		sort(pos+1,pos+n+1);
		cout<<unique(pos+1,pos+n+1)-pos-1;
		return 0;
	}//10pts
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			int dist=abs(pos[i]-pos[j]);
			if(dist<=xyl[i]-xyl[j]) rd[j]++;
			else if(dist<=xyl[j]-xyl[i]) rd[i]++;
		}
	}
	for(int i=1;i<=n;i++){
		if(rd[i]==0) ans++;
	}
	cout<<ans;
	return 0;
}
/*
tu ran fa xian zhe dao ti mei you xie dong xi
bu shang yi duan 
*/
