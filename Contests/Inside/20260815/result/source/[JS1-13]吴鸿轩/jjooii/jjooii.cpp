#include<bits/stdc++.h>
using namespace std;
string s;
int n,k,aa,bb,cnt,sum=2147483647,ans;
int a[200010];
int b[200010],c[200010],d[20010];//J O I
int tot1,tot2,tot3;//J O I
int e[200010],f[200010];//J I
int main(){
	freopen("jjooii.in","r",stdin);
	freopen("jjooii.out","w",stdout);
	cin>>n>>k;
	cin>>s;
	for(int i=0;i<s.length();i++){
		if(s[i]=='J'||aa==1){
			cnt++;
			if(s[i]=='J'){
				a[cnt]=1;
			}if(s[i]=='O'){
				a[cnt]=2;
			}if(s[i]=='I'){
				a[cnt]=3;
			}
			aa=1;
		}
	}
	bb=cnt;
	for(int i=bb;i>=1;i--){
		if(a[i]==3){
			break;
		}
		cnt--;
	}
	for(int i=1;i<=cnt;i++){
		if(a[i]==1){
			tot1++;
			b[tot1]=i;
		}else if(a[i]==2){
			tot2++;
			c[tot2]=i;
		}else{
			tot3++;
			d[tot3]=i;
		}
	}
	for(int i=1;i<=tot1-k+1;i++){
		e[i]=b[i+k-1]-b[i]+1-k;
	}
	for(int i=1;i<tot3;i++){
		f[i]=d[i+k-1]-d[i]+1-k;
	}
	for(int i=1;i<=tot1-k+1;i++){
		for(int j=tot3-k+1;j>=1;j--){
			int ans1=lower_bound(c+1,c+1+tot2,b[i+k-1])-c;
			int ans2=lower_bound(c+1,c+1+tot2,d[j])-c-1;
			if(ans2-ans1+1<k){
				break;
			}
			ans=e[i]+f[j]+d[j]-b[i+k-1]-k-1;
			sum=min(ans,sum);
		}
	}
	if(sum==2147483647){
		cout<<-1;
		return 0;
	}
	cout<<sum<<endl;
	return 0;
}
