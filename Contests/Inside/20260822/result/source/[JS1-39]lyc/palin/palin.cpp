#include<bits/stdc++.h>
using namespace std;
int d[500010];
int c[1000010];
int a[500010][2];
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int _;
	cin>>_;
	while(_--)
	{
		int n;
		string s="";
		memset(d,0,sizeof(d));
		memset(a,0,sizeof(a));
		memset(c,0,sizeof(c));
		cin>>n;
		bool f=0;
		for(int i=1;i<=n*2;i++)
		{
			cin>>c[i];
			if(c[a[c[i]][0]]!=c[i])
			{
				a[c[i]][0]=i;
			}
			else
			{
				a[c[i]][1]=i;
			}
		}
		int l=1,r=2*n;
		while(l<=r)
		{
			string s2=s;
			if(a[c[l]][0]==l)
			{
				if(d[c[l]]==s.size()+1)s+='L',l++;
				else if(a[c[l]][1]-l==2*n+1-2*l||2*n-a[c[l]][1]==2*n+1-2*l||2*n-l==2*n+1-2*l)
				{
					s+='L';l++;
					d[c[l]]=2*n-s.size()*2+1;
				}
			}
			else if(a[c[l]][1]==l&&s.size()+1==d[c[l]])
			{
				s+='L';l++;
			}
			else if(a[c[r]][1]==r)
			{
				if(d[c[r]]==s.size()+1)s+='R',r--;
				else if(r-a[c[r]][0]==2*n+3-2*s.size()||a[c[r]][0]==2*n+3-2*r||r==2*n+3-2*s.size())
				{
					s+='R';
					d[c[r]]=2*n-s.size()*2+1;r--;
				}
			}
			else if(a[c[r]][0]==r&&s.size()+1==d[c[r]])
			{
				s+='R';r--;
			}
			if(s2==s)
			{
				f=1;l=r+1;
			}
			cout<<l<<" "<<r<<" "<<s<<endl;
		}
		if(f){cout<<-1<<endl;continue;}
		else cout<<s<<endl;
	}
    return 0;
}
