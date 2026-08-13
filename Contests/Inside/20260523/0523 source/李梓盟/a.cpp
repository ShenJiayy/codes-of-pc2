#include<bits/stdc++.h>
using namespace std;
int n;
string s;
int main(){
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    cin>>n;
    cin>>s;
    int flag=1;
    if(n%3==0){
        for(int i=0;i<n-3;i+=3){
            if(!(s[i]=='J'&&s[i+1]=='O'&&s[i+2]=='I')){
                flag=0;
                break;
            }
        }
    }else flag=0;
    if(flag){
        for(int i=1;i<=n/3;i++) cout<<"OI";
        for(int i=1;i<=n/3;i++) cout<<"J";
        return 0;
    }
    unsigned long long pos;
    while(1){
        pos=s.find("JOI");
        if(pos==ULLONG_MAX) break;
        s[pos]='O';
        s[pos+1]='I';
        s[pos+2]='J';
    }
    cout<<s;
    return 0;
}
