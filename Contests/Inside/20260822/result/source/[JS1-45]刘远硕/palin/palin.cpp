#include<bits/stdc++.h>
using namespace std;
int T,n,a[100020],b[100020];
bool dfs(int x,string s,int l,int r){
    if (x>n*2){
        int f=1;
        for (int i=1;i<=n && f;i++) if (b[i]!=b[n*2-i+1]) f=0;
        if (f) cout<<s<<"\n";
        return f;
    }
    bool res=0;
    b[x]=a[l];
    res|=dfs(x+1,s+"L",l+1,r);
    if (res) return res;
    b[x]=a[r];
    res|=dfs(x+1,s+"R",l,r-1);
    return res;
}
int main(){
    freopen("palin.in","r",stdin);
    freopen("palin.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n;
        for (int i=1;i<=n*2;i++) cin>>a[i];
        if (!dfs(1,"",1,n*2)) cout<<-1<<"\n";
    }
    return 0;
}