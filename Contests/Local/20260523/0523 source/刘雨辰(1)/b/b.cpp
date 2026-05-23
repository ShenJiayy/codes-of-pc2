#include <bits/stdc++.h>
using namespace std;
int main() 
{
	freopen("b.in","r",stdin);freopen("b.out","w",stdout);
	int n;
	cin>>n;
	int a[5000010];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int mid=ceil((double)n/2.0);
	mid=upper_bound(a+1,a+n+1,a[mid])-a;
	cout<<a[mid];
    return 0;
}

