#include<bits/stdc++.h>
using namespace std;
int t,n,a[500050],ii,ji,ij,jj,p1,p2,f1,f2;
string s1,s2,s3,s4;//左边开头 左边结尾 右边开头 右边结尾 
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		s1="L",s2="L",s3="R",s4="L";
		f1=f2=0;
		cin>>n;
		for(int j=1;j<=n*2;j++) 
		{
			cin>>a[j];
			if(j!=1&&a[j]==a[1]) p1=j;
		}
		for(int j=1;j<n*2;j++) if(a[j]==a[n*2]) p2=j;
		ii=2,ji=n*2,ij=p1-1,jj=p1+1;//第一步取左边；
		for(int i=2;i<=n;i++)
		{
			if(ii<ij&&a[ii]==a[ij])
			{
				ii++,ij--;
				s1+="L",s2="L"+s2;
			}
			else if(ji>jj&&a[ii]==a[jj])
			{
				ii++,jj++;
				s1+="L",s2="R"+s2;
			}
			else if(ii<ij&&a[ji]==a[ij])
			{
				ji--,ij--;
				s1+="R",s2="L"+s2;
			}
			else if(ji>jj&&a[ji]==a[jj])
			{
				ji--,jj++;
				s1+="R",s2="R"+s2;
			}
			else if(ii==ij&&a[ii]==a[jj]) 
			{
				s1+='L',s2='R'+s2;
				ii++,jj++;	
			}	
			else if(ii==ij&&a[ii]==a[ji]) 
			{
				s1+='R',s2='L'+s2;
				ii++,ji--;	
			}
			else if(ji==jj&&a[ji]==a[ii]) 
			{
				s1+='L',s2='R'+s2;
				ji--,ii++;
			}
			else if(ji==jj&&a[ji]==a[ij]) 
			{
				s1+='R',s2='L'+s2;
				ji--,ij--;
			}
			else
			{
				f1=1;
				break;
			}
		}		
		if(f1==0)
		{
			cout<<s1<<s2<<'\n';
			continue;
		}
		ii=1,ji=n*2-1,ij=p2-1,jj=p2+1;
		for(int i=2;i<=n;i++)
		{
			if(ii<ij&&a[ii]==a[ij])
			{
				ii++,ij--;
				s3+="L",s4="L"+s4;
			}
			else if(ji>jj&&a[ii]==a[jj])
			{
				ii++,jj++;
				s3+="L",s4="R"+s4;
			}
			else if(ii<ij&&a[ji]==a[ij])
			{
				ji--,ij--;
				s3+="R",s4="L"+s4;
			}
			else if(ji>jj&&a[ji]==a[jj])
			{
				ji--,jj++;
				s3+="R",s4="R"+s4;
			}	
			else if(ii==ij&&a[ii]==a[jj]) 
			{
				s3+='L',s4='R'+s4;
				ii++,jj++;	
			}
			else if(ii==ij&&a[ii]==a[ji]) 
			{
				s3+='R',s4='L'+s4;
				ii++,ji--;	
			}
			else if(ji==jj&&a[ji]==a[ii]) 
			{
				s3+='L',s4='R'+s4;
				ji--,ii++;
			}
			else if(ji==jj&&a[ji]==a[ij]) 
			{
				s3+='R',s4='L'+s4;
				ji--,ij--;
			}	
			else
			{
				f2=1;
				break;
			}
		}		
		if(f2==0)
		{
			cout<<s3<<s4<<'\n';
			continue;
		}
		cout<<-1<<'\n';
	}
	return 0;
}
