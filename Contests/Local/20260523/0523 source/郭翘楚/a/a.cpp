/*
JJJJJJOI
OIJJJJJJ
*/
#include <bits/stdc++.h>
using namespace std;
string s;
int n;
int pos[500005];
int main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>s;
	for(int i=0,sumj=0,sumoi=0;i<n;)
	{
		if(s[i]=='J')
		{
			sumj++;
			i++;
		}
		else if(s[i]=='O'&&s[i+1]=='I')
		{
			sumoi++;
			i+=2;
		}
		else
		{
			while(sumoi)
			{
				cout<<"OI";
				sumoi--;
			}
			while(sumj)
			{
				cout<<"J";
				sumj--;
			}
			cout<<s[i];
			i++;
		}
		if(i>=n)
		{
			while(sumoi)
			{
				cout<<"OI";
				sumoi--;
			}
			while(sumj)
			{
				cout<<"J";
				sumj--;
			}
			return 0;
		}
	}
//	while(1)
//	{
//		bool f=false;
//		for(int i=0;i<p.size();i++)
//		{
//			if(p[i]>0&&p[i+1]==-1)
//			{
//				swap(p[i],p[i+1]);
//				f=true;
//			}
//		}
//		if(!f) break;
//	}
//	for(int a:p)
//	{
////		cout<<a<<" ";
//		if(a>0)
//		{
//			while(a)
//			{
//				a--;
//				cout<<'J';
//			}
//		}
//		else if(a==-1)
//		{
//			cout<<"OI";
//		}
//		else if(a==-2)
//		{
//			cout<<'O';
//		}
//		else cout<<'I';
//	}
}
