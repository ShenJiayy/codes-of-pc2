#include <bits/stdc++.h>

using namespace std;
using nint=long long;

const int maxn=2e5+5;

nint n,k,lj,lo,li,c[maxn],l[maxn],r[maxn],de[maxn];
string s;
int main(){
	freopen("jjooii.in","r",stdin);
	freopen("jjooii.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
		r[i]=i+1;l[i]=i-1;
	}
    cin>>s;
    s=" "+s; 
    int fj=0,fo=0,fi=0,cntj=0,cnto=0,cnti=0;
    for(int i=1;i<=n;i++){
    	if(s[i]=='J'){
    		cntj++;
    		c[i]=1;
    		if(lj>0){
    			l[i]=lj;
    			r[lj]=i;
			} 
			else{
				l[i]=0;
				r[0]=i;
			}
			lj=i;
		}
    	if(s[i]=='O'){
    		c[i]=2;
    		if(cntj>=k){
    			fj=1;
    			cnto++;
    			if(lo>0){
    				l[i]=lo;
    				r[lo]=i;
				}
				lo=i;
			}
		}
		if(s[i]=='I'){
			c[i]=3;
			if(cnto>=k){
				fo=1;
				cnti++;
				if(li>0){
    				l[i]=li;
    				r[li]=i;
				}
				li=i;
			}
		}
		if(cnti>=k){
			fi=1;
		}
	}
	if(!((fj&fo)&fi)){
		cout<<-1;
		return 0;
	}
	int ans = INT_MAX;
	int h=0;
	cntj=0;
	for(int j=r[0];c[r[j]]==1;j=r[j]){//c[j]满足cntj>=k的 J 
		cntj++;
		if(cntj<k)continue;
		if(cntj>=k){
			h=r[h];
			cntj--;
		}
		int cnt=j-h+1-k;
		int to;
		cnto=0;
		for(int o=j;o<r[j];o++){//c[o]找最近的O 
			if(c[o]==2){
				cnt+=o-j-1;
				to=o;
				break;
			}
		}
		int o=to;
		for(int x=1;x<=k-1;x++){
			o=r[o];
			cnt+=o-l[o]-1;
		}
		int ti;
		for(int i=o+1;i<r[o];i++){
			if(c[i]==3){
				cnt+=i-o-1;
				ti=i;
				break;
			}
		}
		int i=ti;
		for(int x=1;x<=k-1;x++){
			i=r[i];
			cnt+=i-l[i]-1;
		}
		ans=min(ans,cnt);
	}
	cout<<ans;
    return 0;
}
