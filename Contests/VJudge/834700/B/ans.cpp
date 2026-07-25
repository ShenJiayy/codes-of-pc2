#include<iostream> 
#include<cstdio> 
#include<queue>
using namespace std; 
int n,m;
priority_queue<int,vector<int>,greater<int> >que1;//xiao
priority_queue<int>que2;//da
string s;
int cnt1,cnt2;
int main()
{ 
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int a;
        scanf("%d",&a);
        que2.push(a);cnt2++;
    }
    for(int i=1;i<=n/2;i++)
    {
        int x=que2.top();
        que2.pop();cnt2--;
        que1.push(x);cnt1++;
    }
    scanf("%d",&m);
    for(int i=1;i<=m;i++)
    {
        cin>>s;
        if(s[0]=='a')
        {
            int x;
            scanf("%d",&x);
            n++;
            int l=que2.top();
            if(x>l)que1.push(x),cnt1++;
            else que2.push(x),cnt2++;
        }
        else
        {
            while(cnt2<(n+1)/2)
            {
                int x=que1.top();
                que1.pop();cnt1--;
                que2.push(x);cnt2++;
            }
            while(cnt2>(n+1)/2)
            {
                int x=que2.top();
                que2.pop();cnt2--;
                que1.push(x);cnt1++;    
            }
            if(cnt2==(n+1)/2)
            cout<<que2.top()<<endl;
        }
    }
    return 0;
}
