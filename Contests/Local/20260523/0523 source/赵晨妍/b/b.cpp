#include <bits/stdc++.h>
using namespace std;

int n;

int main()
{
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	
	cin >> n;
	vector<int> A(n);
	for(int i = 0;i < n;i++)
		cin >> A[i];
	sort(A.begin(),A.end());
	int minn = 1e9,x = 0;
	for(int i = 1;i < n;i++)
	{
		int cnt1 = i,cnt2 = n-i;
		int num = abs(cnt1-cnt2);
		if(num < minn)
		{
			minn = num;
			x = A[i];
		}
		else if(num == minn)
		{
			if((n-i) < (n-(x==A[i]?i:lower_bound(A.begin(),A.end(),x)-A.begin())))
				x = A[i];
		} 
	}
	cout << x;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
