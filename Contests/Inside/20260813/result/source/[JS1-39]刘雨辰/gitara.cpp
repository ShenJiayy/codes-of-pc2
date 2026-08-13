#include<bits/stdc++.h>
using namespace std;
int n,p;stack<int>mx[10];int a,b;
int main()
{
    freopen("gitara.in","r",stdin);
    freopen("gitara.out","w",stdout);
	int ans=0;
	cin>>n>>p;
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&a,&b);
		while(!mx[a].empty()&&b<mx[a].top())
		{
			mx[a].pop();ans++;
		}
		if(mx[a].empty()||b!=mx[a].top()){mx[a].push(b);ans++;}
	}
	cout<<ans;
	return 0;
}

