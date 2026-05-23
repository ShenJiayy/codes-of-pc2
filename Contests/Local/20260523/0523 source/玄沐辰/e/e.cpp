#include <bits/stdc++.h>
using namespace std;
int n, m;
vector <int> v[300010];
bool isused[300010][2];

struct nd
{
	int ind;
	int deep;
	nd(int i, int d)
	{
		ind = i, deep = d;
	}
};

inline int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}

int bfs(int s)
{
	memset(isused, 0, sizeof isused);
	queue<nd> q;
	nd x(s, 1);
	q.push(x);
	isused[s][1] = 1;
	while (!q.empty())
	{
		int id = q.front().ind, d = q.front().deep;
		q.pop(); 
		for (int i = 0; i < v[id].size(); i++)
		{
			if (v[id][i] > id && d % 2 && !isused[v[id][i]][0])
			{
				nd x(v[id][i], 0);
				q.push(x);
//				cout << v[id][i] << " 0 \n";
				isused[v[id][i]][0] = 1;
			}
			if (v[id][i] < id && d % 2 == 0 && !isused[v[id][i]][1])
			{
				nd x(v[id][i], 1);
				q.push(x);
//				cout << v[id][i] << " 1 \n";
				isused[v[id][i]][1] = 1;
			}
		}
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		if (!(isused[i][0] || isused[i][1]))
		{
			cnt++;
		}
	}
	return cnt;
}

int main()
{
	freopen("e.in", "r", stdin);
	freopen("e.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int a = read(), b = read();
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int i = 1; i <= n; i++)
	{
		cout << bfs(i) << "\n";
	}
	return 0;
}
