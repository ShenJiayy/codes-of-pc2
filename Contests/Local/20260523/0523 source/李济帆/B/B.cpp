#include<bits/stdc++.h>
using namespace std;
int a[500005],c[500005],d[500005],cur;
map<int,int> b;
int main()
{
	freopen("B.in", "r", stdin);
	freopen("B.out", "w", stdout);
	int n;
	cin>>n;
	for(int i =1;i<=n;i++)
	{
		cin>>a[i];
//		if(b[a[i]]==0)
//		{
//			c[++cur]=1;
//		}
//		b[a[i]]++;
	}
	sort(a+1,a+n+1);
	int i =n,minn=1e9,id=0;
	while(i>=1)
	{
		int j=i;
		while(i>=1&&a[i]==a[j])
		{
			i--;
		}
		if(minn>abs((n-i)-i))
		{
			id=i;
			minn=abs((n-i)-i);
		}
	}
	cout<<a[id+1];
	return 0;
}


