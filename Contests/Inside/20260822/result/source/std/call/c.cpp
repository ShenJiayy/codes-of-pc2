#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>

const int N=100005,P=998244353;

int n,m,Q;
std::vector<int> G1[N],G2[N];
//为了求快（写代码快，不是运行快）考试时的图我全用vector了，，，
//G2是函数调用图，G1是G2的反图用于第一遍拓扑排序

int cnt[N];//记录每个函数的执行次数

int data[N],tp[N],mul[N],add[N],pos[N];
//data：原序列
//tp：记录每个操作的类型
//mul：记录每个操作执行一次后会把序列乘多少，操作1和3初始化为1，操作2初始化为读入数据、
//add：记录操作1的加数
//pos：记录操作1的操作位置




int deg1[N];
void topo1()//用于算出每个函数执行完会将序列乘多少
//事实上用记忆化搜索更简单，，，
{
	static std::queue<int> q;
	for(int i=0;i<=m;++i)
	{
		deg1[i]=G2[i].size();
		if(deg1[i]==0)q.push(i);
	}
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for(int i=0;i!=G1[u].size();++i)
		{
			int v=G1[u][i];
			mul[v]=(long long)mul[v]*mul[u]%P;//直接递推，很容易
			--deg1[v];
			if(deg1[v]==0)q.push(v);
		}
	}
}





int deg2[N];
void topo2()//用于算出每个函数的调用次数
{
	static std::queue<int> q;
	for(int i=0;i<=m;++i)
	{
		deg2[i]=G1[i].size();
		if(deg2[i]==0)q.push(i);
	}
	while(!q.empty())
	{
		int u=q.front();
		int now_mul=1;//当前函数内的乘法标记
		q.pop();
		for(int i=G2[u].size();i!=0;--i)
         //注意这里要倒着遍历边表
         //因为每个函数执行完乘的倍数只影响在它前面执行的函数
		{
			int v=G2[u][i-1];
			cnt[v]=(cnt[v]+(long long)cnt[u]*now_mul)%P;
             //当前乘法标记可以转化为前一个函数的执行次数
			now_mul=(long long)now_mul*mul[v]%P;
			--deg2[v];
			if(deg2[v]==0)q.push(v);
		}
	}
}



#include<cctype>
char gc()
{
	static char buf[1<<16],*p1=buf,*p2=buf;
	if(p1==p2)
	{
		p2=(p1=buf)+fread(buf,1,1<<16,stdin);
		if(p1==p2)return EOF;
	}
	return *p1++;
}

template<typename _Tp>
void read(_Tp &x)
{
	x=0;
	char c=gc();
	while(!isdigit(c))c=gc();
	while(isdigit(c))x=x*10-48+c,c=gc();
}


int main()
{
	read(n);
	for(int i=1;i<=n;++i)read(data[i]);
	read(m);
	mul[0]=1;
	for(int i=1;i<=m;++i)
	{
		read(tp[i]);
		if(tp[i]==1)
		{
			read(pos[i]),read(add[i]);
			mul[i]=1;
		}
		if(tp[i]==2)
		{
			read(mul[i]);
		}
		if(tp[i]==3)
		{
			mul[i]=1;
			int len;
			read(len);
			for(int j=0;j<len;++j)
			{
				int v;
				read(v);
				G1[v].push_back(i);
				G2[i].push_back(v);
			}
		}
	}
	read(Q);
	cnt[0]=1;//把0号函数作为主函数
	for(int i=0;i<Q;++i)
	{
		int x;
		read(x);
		G2[0].push_back(x);
		G1[x].push_back(0);
	}
	topo1();
	topo2();
	for(int i=1;i<=n;++i)data[i]=(long long)data[i]*mul[0]%P;
    //！！！不要忘记主函数本身的乘法标记对答案的影响！！！
	for(int i=1;i<=m;++i)
	{
		if(tp[i]==1)//对于每个操作1，由于没有了操作2和3的影响，可以直接计算答案
		{
			data[pos[i]]=(data[pos[i]]+(long long)cnt[i]*add[i])%P;
		}
	}
	for(int i=1;i<=n;++i)
	{
		printf("%d ",data[i]);
	}
}
