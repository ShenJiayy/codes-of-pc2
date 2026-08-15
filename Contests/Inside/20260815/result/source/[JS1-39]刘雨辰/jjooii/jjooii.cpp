#include<bits/stdc++.h>
using namespace std;
int idj[200010],ido[200010],idi[200010];
int main()
{
	freopen("jjooii.in","r",stdin);
	freopen("jjooii.out","w",stdout);
	int n;
	int k;
	string s;
	int ans=-1;
	cin>>n>>k>>s;
	s=' '+s;
	int cntj=0,cnto=0,cnti=0;
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='J')idj[++cntj]=i;
		if(s[i]=='O')ido[++cnto]=i;
		if(s[i]=='I')idi[++cnti]=i;
	}
	int ii=1,io=1;
	for(int ij=1;ij<=cntj-k+1;ij++)
	{
		while(ido[io]<idj[ij+k-1]&&io<cnto-k+1)io++;
		while(idi[ii]<ido[io+k-1]&&ii<cnti-k+1)ii++;
		if(ido[io]<idj[ij+k-1]||idi[ii]<ido[io+k-1])break;
		int ans2=0;
		//cout<<idj[ij]<<" "<<ido[io]<<" "<<idi[ii]<<endl;
		for(int i=0;i<k;i++)
		{
			if(i==0)ans2+=ido[io]-idj[ij+k-1]-1+idi[ii]-ido[io+k-1]-1;
			else ans2+=idj[ij+i]-idj[ij+i-1]-1+ido[io+i]-ido[io+i-1]-1+idi[ii+i]-idi[ii+i-1]-1;
			//cout<<i<<" "<<ans2<<endl;
		}
		ans=min(ans,ans2);if(ans==-1)ans=ans2;
	}
	cout<<ans;
	return 0;
}

