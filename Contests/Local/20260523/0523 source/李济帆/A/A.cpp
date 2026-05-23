#include<iostream>
using namespace std;
string s;
//bool is2()
//{
//	for(int i =1;i<=n;i+=3)
//	{
//		if(s[i]!='J'||s[i+1]!='O'||s[i+2]!='I')
//		{
//			return 0;
//		}
//	}
//	return 1;
//}
int main()
{
	freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);
	int n;
	cin>>n;
	cin>>s;
	s=' '+s;
	int jj=0,oi=0;
	for(int i =1;i<=n;i++)
	{
		//cout<<i<<" "<<s[i]<<endl;
		//cout<<jj<<" "<<oi<<endl;
		if(s[i]=='J')
		{
			//cout<<1<<endl;
			jj++;
		}
		else if(s[i]=='O'&&s[i+1]=='I')
		{
			//cout<<2<<endl;
			oi++;
		}
		else if(s[i]=='I'&&s[i-1]=='O')
		{
			continue;
		}
		else
		{
			//cout<<s[i];
			//cout<<3;
			for(int j =1;j<=oi;j++)
			{
				cout<<"OI";
			}
			for(int j =1;j<=jj;j++)
			{
				cout<<"J";
			}
			oi=0;
			jj=0;
			cout<<s[i];
		}
	}
	for(int i =1;i<=oi;i++)
	{
		cout<<"OI";
	}
	for(int i =1;i<=jj;i++)
	{
		cout<<"J";
	}
//	bool b=1;
//	while(b)
//	{
//		b=0;
//		for(int i=3;i<=n;i++)
//		{
//			if(s[i-2]=='J'&&s[i-1]=='O'&&s[i]=='I')
//			{
//				//cout<<i<<endl;
//				b=1;
//				s[i-2]='O';
//				s[i-1]='I';
//				s[i]='J';
//			}
//		}
//	}
//	cout<<s;
	return 0;
}
