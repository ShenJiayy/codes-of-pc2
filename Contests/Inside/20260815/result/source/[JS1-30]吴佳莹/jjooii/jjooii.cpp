#include<bits/stdc++.h>
using namespace std;
const int N=4e5+5;
int n,m,f[4][N],a[N],b[N],c[N];
int cnt1,cnt2,cnt3,ans=1e9;
string s;
int main(){
	freopen("jjooii.in","r",stdin);
	freopen("jjooii.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]=='J') a[++cnt1]=i;
		if(s[i]=='O') b[++cnt2]=i;
		if(s[i]=='I') c[++cnt3]=i;
	}
	cnt1=cnt2=cnt3=0;
	for(int i=0;i<s.size();i++){
		if(s[i]=='J'){
			cnt1++;
			f[1][i]=a[cnt1+m-1];
			f[2][i]=b[cnt2+m];
			f[3][i]=c[cnt3+m];
		}
		if(s[i]=='O'){
			cnt2++;
			f[1][i]=a[cnt1+m];
			f[2][i]=b[cnt2+m-1];
			f[3][i]=c[cnt3+m];
		}
		if(s[i]=='I'){
			cnt3++;
			f[1][i]=a[cnt1+m];
			f[2][i]=b[cnt2+m];
			f[3][i]=c[cnt3+m-1];	
		}
	}
	for(int i=0;i<s.size();i++){
		if(s[i]!='J') continue;
		int pos1=f[1][i];
		int pos2=f[2][pos1];
		int pos3=f[3][pos2];
		if(pos1==0||pos2==0||pos3==0) continue;
		ans=min(ans,pos3-i+1-3*m);
	}
	if(ans!=1e9) cout<<ans;
	else cout<<-1;
	return 0;
}
