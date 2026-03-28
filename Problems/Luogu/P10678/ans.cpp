#include<bits/stdc++.h>
using namespace std;
#define forl(i,a,b) for(register long long i=a;i<=b;i++)
#define forr(i,a,b) for(register long long i=a;i>=b;i--)
#define forll(i,a,b,c) for(register long long i=a;i<=b;i+=c)
#define forrr(i,a,b,c) for(register long long i=a;i>=b;i-=c)
#define pb push_back
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define endl '\n'
#define QwQ return 0;
#define ll long long
ll t;
ll n;
queue<ll>q[200010];
ll a[200010],b[200010];
void solve()
{
	cin>>n;
	ll ma=0;
	forl(i,1,n)
		cin>>a[i],ma=max(ma,a[i]),b[a[i]]++,q[a[i]].push(i);
	ll S=0;
	while(S<n-1)
	{
		ll id1=q[1].front();
		q[1].pop();
		cout<<id1<<' ';
		ll pd=0;
		forl(j,2,ma)
		{
			if(!q[j].empty())
			{
				id1=q[j].front();
				cout<<id1<<endl;
				S++;
				q[j].pop();
				q[j-1].push(id1);
				ll L=j-1;
				while(L>=2)
				{
					id1=q[L].front();
					cout<<id1<<' ';
					cout<<q[1].front()<<endl;
					S++;
					q[1].pop();
					q[L].pop();
					q[--L].push(id1);	
				}
				pd=1;
				break;
			}
		}
		if(!pd)
		{
			id1=q[1].front();
			cout<<id1<<endl;
			S++;
			q[1].pop();
		}
	}
}
int main()
{
	IOS;
	t=1;
 	cin>>t;
	while(t--)
		solve();
	QwQ;
}
