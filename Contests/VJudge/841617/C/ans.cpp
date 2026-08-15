#include <bits/stdc++.h>
#define N 200005
#define inf 0x3f3f3f3f
using namespace std;
int cntj[N],cnto[N],cnti[N],n,k,cj,co,ci,lo,li,ed,ans;
string s;
int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	while(cin>>n>>k>>s){
		s=" "+s; cj=co=ci=0;
		for(int i=1;i<=n;i++){//记录位置
			if(s[i]=='J') cntj[++cj]=i;
			if(s[i]=='O') cnto[++co]=i;
			if(s[i]=='I') cnti[++ci]=i;
		}
		lo=li=1; ans=inf;
		for(int i=1;i<=cj;i++){//遍历每一个J
			if(i+k-1>cj) break;//如果后面不足k个，跳出循环。后同理。
        	//注意lo和li不用每次从1开始，位置是单调递增的。
			ed=cntj[i+k-1];
			while(cnto[lo]<=ed&&lo<=co) lo++;
			if(lo+k-1>co) break;
			ed=cnto[lo+k-1];
			while(cnti[li]<=ed&&li<=ci) li++;
			if(li+k-1>ci) break;
			ans=min(ans,cnti[li+k-1]-cntj[i]+1-3*k);//总区间减去不用删除的长度即3*k
		}
		if(ans!=inf) cout<<ans<<endl;
		else cout<<-1<<endl;
	}
	return 0;
}
