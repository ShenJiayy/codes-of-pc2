#include<bits/stdc++.h>
using namespace std;
int n,m,ans=2e9;
int l[500005],r[500005];
int main(){
	freopen("interval.in","r",stdin);
	freopen("interval.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&l[i],&r[i]);
	if(m==2){
		for(int i=1;i<n;i++)
			for(int j=i+1;j<=n;j++)
				if((l[j]>=l[i]&&l[j]<=r[i])||(r[j]<=r[i]&&r[j]>=l[i]))
					ans=min(ans,max(r[i]-l[i],r[j]-l[j])-min(r[i]-l[i],r[j]-l[j]));
		if(ans==2e9)cout<<"-1";else printf("%d",ans);
		return 0;
	}
	if(m==3){
		for(int i=1;i<n-1;i++)
		for(int j=i+1;j<n;j++)
			if((l[j]>=l[i]&&l[j]<=r[i])||(r[j]<=r[i]&&r[j]>=l[i])){
				int pl=max(l[j],l[i]),pr=min(r[i],r[j]);
				for(int k=j+1;k<=n;k++)
					if((l[k]>=pl&&l[k]<=pr)||(r[k]<=pr&&r[k]>=pl))
						ans=min(ans,max(r[i]-l[i],max(r[j]-l[j],r[k]-l[k]))-min(r[i]-l[i],min(r[j]-l[j],r[k]-l[k])));
			}
		if(ans==2e9)cout<<"-1";else printf("%d",ans);
		return 0;
	}
	return 0;
}
