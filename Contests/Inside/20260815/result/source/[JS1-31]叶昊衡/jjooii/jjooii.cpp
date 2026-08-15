#include<bits/stdc++.h>
using namespace std;
int n,k,ans=1e9;
string s;
int jsum[200005],osum[200005],isum[200005];
int main()
{
	freopen("jjooii.in","r",stdin);
	freopen("jjooii.out","w",stdout);
	cin>>n>>k>>s;
	s='@'+s;
	for(int i=1;i<=n;i++)
	{
		jsum[i]=jsum[i-1],osum[i]=osum[i-1],isum[i]=isum[i-1];
		if(s[i]=='J') jsum[i]++;
		if(s[i]=='O') osum[i]++;
		if(s[i]=='I') isum[i]++;
	}
	for(int i=1;i<=n;i++)
		if(s[i]=='J')
		{
			int l,r,mid,J=-1,O=-1,I=-1;
			l=i,r=n;
			while(l<=r)
			{
				mid=(l+r)/2;
				if(jsum[mid]-jsum[i-1]>k) r=mid-1;
				else if(jsum[mid]-jsum[i-1]<k) l=mid+1;
				else J=mid,r=mid-1;
			}
			l=J,r=n;
			if(J!=-1)
				while(l<=r)
				{
					mid=(l+r)/2;
					if(osum[mid]-osum[J-1]>k) r=mid-1;
					else if(osum[mid]-osum[J-1]<k) l=mid+1;
					else O=mid,r=mid-1;
				}
			l=O,r=n;
			if(O!=-1)
				while(l<=r)
				{
					mid=(l+r)/2;
					if(isum[mid]-isum[O-1]>k) r=mid-1;
					else if(isum[mid]-isum[O-1]<k) l=mid+1;
					else I=mid,r=mid-1;
				}
			if(J!=-1&&O!=-1&&I!=-1)
				ans=min(ans,I-i+1-3*k);
		}
	if(ans!=1e9) cout<<ans;
	else cout<<-1;
}
