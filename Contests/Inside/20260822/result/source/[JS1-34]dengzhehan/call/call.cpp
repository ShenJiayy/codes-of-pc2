#include <bits/stdc++.h>
using namespace std;

struct fs{
    int op, o1, o2;
    vector <int> os;
} ff[100005];

int n, a[100005];
int m, q, f;
const int Mod = 998244353;

void run_func(int fid){
    if (ff[fid].op == 1){
        a[ff[fid].o1] += ff[fid].o2;
        a[ff[fid].o1] %= Mod;
        return ;
    }
    if (ff[fid].op == 2){
        for (int i = 1; i <= n; i++){
            a[i] *= ff[fid].o1;
            a[i] %= Mod;
        }
    }
    if (ff[fid].op == 3){
        for (int i = 0; i < ff[fid].o1; i++){
            run_func(ff[fid].os[i]);
        }
    }
    return ;
}

int main(){
    freopen("call.in", "r", stdin);
    freopen("call.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    cin >> m;
    for (int i = 1; i <= m; i++){
        cin >> ff[i].op;
        if (ff[i].op == 1) cin >> ff[i].o1 >> ff[i].o2;
        if (ff[i].op == 2) cin >> ff[i].o1;
        if (ff[i].op == 3){
            cin >> ff[i].o1;
            int tmp;
            for (int j = 1; j <= ff[i].o1; j++){
                cin >> tmp;
                ff[i].os.push_back(tmp);
            }
        }
    }
    cin >> q;
    for (int i = 1; i <= q; i++){
        cin >> f;
        run_func(f);
    }
    for (int i = 1; i <= n; i++){
        cout << a[i] << ' ';
    }
    return 0;
}