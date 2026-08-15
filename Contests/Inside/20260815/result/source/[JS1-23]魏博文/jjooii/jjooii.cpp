#include<bits/stdc++.h>
using namespace std;
string s;
const int N=2e5+5;
int a[N],cnt,kk[N][5],g[N],g2[N],ans=1e9;
vector<int> p1,p2,p3;
int main(){
	freopen("jjooii.in","r",stdin);
	freopen("jjooii.out","w",stdout);
	int n,k,s1,s2;
	cin>>n>>k>>s;
	for(int i=0;i<n;i++){
		if(s[i]=='J'){
			s1=i;
			break;
		}
	}
	for(int j=n-1;j>=0;j--){
		if(s[j]=='I'){
			s2=j;
			break;
		}
	}
	p1.push_back(0);
	p2.push_back(0);
	p3.push_back(0);
	for(int i=s1;i<=s2;i++){
		kk[i][1]=kk[i-1][1];
		kk[i][2]=kk[i-1][2];
		kk[i][3]=kk[i-1][3];
		if(s[i]=='J'){
			kk[i][1]++;
		}
		if(s[i]=='O'){
			kk[i][2]++;
		}
		if(s[i]=='I'){
			kk[i][3]++;
		}
    }
	for(int i=s1;i<=s2;i++){
		if(s[i]=='J'){
			p1.push_back(i);
		}
		if(s[i]=='O'){
			p2.push_back(i);
		}
		if(s[i]=='I'){
			p3.push_back(i);
		}
	}
	//cout<<p1.size();
	//for(int i=1;i<=p3.size();i++) cout<<p3[i]<<' ';
	/*int size=0,v=0,h=0;
	for(int i=s2;i>=s1;i--){
		if(s[i]=='I'){
			size++;
			if(size-v==k){
				int vv=q3[v+1];
				int len=vv-i+1;
				g[h]=len-k;
				v++;
			}
		}
		else if(s[i]=='O'){
			h++;
			g[h]=g[h-1];
		}
		else{
			g[h]++;
		}
		if(k[s2][2]-h==k) break;
	}*/
	//int size=0,v=0,h=0;
	/*for(int i=s1;i<=s2;i++){
		if(s[i]=='J'){
			size++;
			if(size-v==k){
				int vv=p1[v+1];
				int len=vv-i+1;
				g2[h]=len-k;
				v++;
			}
		}
		else if(s[i]=='O'){
			int vv=p2[h+k];
			int ww=kk[i][3];
			int uu=p3[ww+1];
			if(ww+1+k<=p3.size()-1){
				int len=p3[ww+1+k]-uu+1-k;
				ans=min(ans,g2[h]+len+p2[h+k]-i+1-k);
			}
			h++;
			g2[h]=g2[h-1];
		}
		else{
			g2[h]++;
		}
		if(kk[s2][2]-h>k) break;
	}*/
	for(int i=1;i<p1.size();i++){
		//if(s[i]!='J') continue;
		if(i+k-1>p1.size()-1) break;
		int v1=p1[i+k-1];
		if(kk[v1][2]+k>p2.size()-1) break;
		int u2=p2[kk[v1][2]+1];
		int v2=p2[kk[v1][2]+k];
		if(kk[v2][3]+k>p3.size()-1) break;
		int u3=p3[kk[v2][3]+1];
		int v3=p3[kk[v2][3]+k];
		//cout<<i<<" "<<v1<<" "<<u2<<" "<<v2<<" "<<u3<<" "<<v3<<endl;
		if(v3<=s2&&u3<=s2&&v2<=s2&&u2<=s2&&v1<=s2){
			int len=v3-p1[i]+1;
			ans=min(ans,len-3*k);
		}
	}
	if(ans!=1e9){
		cout<<ans;
	}
	else cout<<"-1";
}
