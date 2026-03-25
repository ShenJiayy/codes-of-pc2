#include <bits/stdc++.h>
#include <queue>
using namespace std;
int n;
bool flag;
struct crystal {
    int a,x,cnt,pos;//a,x为题目意思，cnt为比它小的水晶和它不能配对的个数，pos为排序前水晶的编号
} b[500005];
bool cmp(const crystal &x, const crystal &y) {
    return x.a<y.a;
}
bool operator <(const crystal &x, const crystal &y) {
    if(x.cnt==y.cnt) return x.a>y.a;
    return x.cnt<y.cnt;
}
long long ans;
priority_queue <crystal> h;//注意我在实现时优先队列是以cnt排序的，而cnt并不等于锁定的水晶数（就是这里的策略和前面说的略有不同），但这种策略也是可以保证出解的，为方便实现这里就用这种。
int main() {
    scanf("%d",&n);
    for(int i=1; i<=n; i++) scanf("%d",&b[i].a);
    for(int i=1; i<=n; i++) scanf("%d",&b[i].x);
    for(int i=1; i<=n; i++) b[i].pos=i;
    if(n==2) {
        if(b[1].x==-1&&b[2].x==-1) printf("%d\n1 2\n",min(b[1].a,b[2].a));
        else printf("-1\n");
        return 0;
    }
    for(int i=1; i<=n; i++) if(b[i].x!=-1) b[b[i].x].cnt++;
    sort(b+1,b+n+1,cmp);
    for(int i=(n>>1)+1; i<n; i++) {
        h.push(b[i]);
    }
    if(h.top().x!=-1&&h.top().cnt==n-2) {//最后一个水晶暂不入堆，此时倒数第二水晶点cnt为n-2且x不为-1就表示它和所有水晶都无法配对。
        printf("-1\n");
        return 0;
    }
    h.push(b[n]);
    if(h.top().cnt==n-1) {//最后一个水晶如堆后，如果cnt==n-1，就代表它无法和前面的所有水晶配对
        printf("-1\n");
        return 0;
    }
    crystal t=h.top();//只有cnt最多的水晶才可能锁定前半段的所有水晶
    for(int i=1; i<=(n>>1); i++) {
        if(b[i].x!=t.pos) flag=1;
    }
    if(flag) {
        for(int i=(n>>1); i>=1; i--) {
            ans+=1ll*((n>>1)-i+1)*b[i].a;
        }
        printf("%lld\n",ans);
        for(int i=(n>>1); i>=1; i--) {
            t=h.top();
            if(b[i].x!=t.pos) {
                printf("%d %d\n",b[i].pos,t.pos);
                h.pop();
            } else {//如果cnt最大的水晶不能和该水晶配对，那第二大的一定可以（我们只对后半段的水晶入堆）
                h.pop();
                printf("%d %d\n",b[i].pos,h.top().pos);
                h.pop();
                h.push(t);
            }
        }
    } else {
        int p;
        for(p=(n>>1)+1; p<=n; p++) {
            if(b[p].a<t.a) {
                if(b[p].x!=t.pos) break;
            }
            if(b[p].a>t.a) {
                if(t.x!=b[p].pos) break;
            }
        }
        ans+=min(b[p].a,t.a);
        for(int i=(n>>1)-1; i>=1; i--) {
            ans+=1ll*((n>>1)-i+1)*b[i].a;
        }
        printf("%lld\n",ans);
        printf("%d %d\n",t.pos,b[p].pos);
        h.pop();
        for(int i=(n>>1)-1,j=n>>1; j<=n&&i>=1; i--,j++) {//一定注意分界点换了
            if(j==p||b[j].a==t.a) j++;
            printf("%d %d\n",b[i].pos,b[j].pos);
        }
    }
    return 0;
}
