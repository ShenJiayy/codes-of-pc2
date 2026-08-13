#include<iostream>
using namespace std;
int n,m,x,cnt;
int main(){
    freopen("rect.in","r",stdin);
	freopen("rect.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
    cin>>n>>m;
    int pre[n+1][m+1];
    for(int i=0;i<=n;i++)
        for(int j=0;j<=m;j++) pre[i][j]=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++) cin>>x,pre[i][j]=pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1]+x;
    for(int x1=1;x1<=n;x1++)
        for(int y1=1;y1<=m;y1++)
            for(int x2=x1;x2<=n;x2++)
                for(int y2=y1;y2<=m;y2++)
                    if(pre[x2][y2]-pre[x1-1][y2]-pre[x2][y1-1]+pre[x1-1][y1-1]==(y2-y1+1)*(x2-x1+1)) cnt++;
    cout<<cnt;
    return 0;
}
