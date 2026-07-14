#include<bits/stdc++.h>
#define N 250005
using namespace std;
int n,xx,yy;char ch;
struct Point{int x,y,id;};
struct Point p[N];
inline bool cmp1(Point a,Point b){
    return a.x^b.x?a.x<b.x:a.y<b.y;
}
inline bool cmp2(Point a,Point b){
 return a.y^b.y?a.y<b.y:a.x<b.x;
}
inline bool cmp3(Point a,Point b){
    return a.id<b.id;
}
int ans(INT_MAX),s,t,w,ss,tt;
int main(){
    scanf("%d",&n);p[0]=(Point){0,0,0};
    //预处理出所有会走到的点
    for(int i(1);i<=n;++i){
        scanf(" %c",&ch);
        if(ch=='N') ++xx;
        if(ch=='S') --xx;
        if(ch=='W') --yy;
        if(ch=='E') ++yy;
        p[i]=(Point){xx,yy,i};
    }
    //找到横坐标相同的点
    /*
    sort(p,p+1+n,cmp1);
    for(int i(1);i<=n;++i){
        if(p[i].x^p[i-1].x) continue;
        if(abs(p[i].id-p[i-1].id)^1){
            w=abs(p[i].y-p[i-1].y);
            if(p[i].id<p[i-1].id){ss=i;tt=i-1;}
            else{ss=i-1;tt=i;}
            if(w<ans){ans=w;s=p[ss].id;t=p[tt].id;}
            else if(!(w^ans)){
                if(p[ss].id<s){s=p[ss].id;t=p[tt].id;}
                else if(!(p[ss].id^s)) t=max(p[tt].id,t);
            }
        }
    }
    */
   for (int i = 1; i <= n; ++i) {
        // 如果x坐标不同，跳过（只处理相同x坐标的相邻点）
        if (p[i].x != p[i-1].x) continue;
        
        // 检查相邻两个点是否属于不同的配对（id相差不为1）
        if (abs(p[i].id - p[i-1].id) != 1) {
            int w = abs(p[i].y - p[i-1].y);
            
            // 确定ss和tt，使得ss指向id较小的点，tt指向id较大的点
            int ss, tt;
            if (p[i].id < p[i-1].id) {
                ss = i;
                tt = i - 1;
            } else {
                ss = i - 1;
                tt = i;
            }
            
            // 更新最优解
            if (w < ans) {
                ans = w;
                s = p[ss].id;
                t = p[tt].id;
            } else if (w == ans) {
                // 当距离相等时，按字典序更新
                if (p[ss].id < s) {
                    s = p[ss].id;
                    t = p[tt].id;
                } else if (p[ss].id == s) {
                    t = max(p[tt].id, t);
                }
            }
        }
    }
    sort(p,p+1+n,cmp2);
    for(int i(1);i<=n;++i){
        if(p[i].y^p[i-1].y) continue;
        if(abs(p[i].id-p[i-1].id)^1){
            w=abs(p[i].x-p[i-1].x);
            if(p[i].id<p[i-1].id){ss=i;tt=i-1;}
            else{ss=i-1;tt=i;}
            if(w<ans){ans=w;s=p[ss].id;t=p[tt].id;}
            else if(!(w^ans)){
                if(p[ss].id<s){s=p[ss].id;t=p[tt].id;}
                else if(!(p[ss].id^s)) t=max(p[tt].id,t);
            }
        }
    }//找到纵坐标相同的点
    printf("%d %d %d ",ans,s,t);
    sort(p+1,p+1+n,cmp3);//这个排序可以不要，但是代码会复杂一点，我懒得写就直接排序了
    if(p[s].x^p[t].x) puts(p[s].x<p[t].x?"N":"S");
    else puts(p[s].y<p[t].y?"E":"W");
    return 0;
}
