#include <bits/stdc++.h>
using namespace std;
int cnt[128]; // 统计每种字符出现的次数
char ans[1000005];

void solve()
{
    for(char c = 'a'; c <= 'z'; c++)
        cnt[c] = 0; // 数组清空
    
    string s;
    cin >> s;
    
    for(char c : s)
        cnt[c]++; // 统计每种字符出现的次数
    
    vector<pair<int, char>> G; // 将各英文字母按 <数量,字符> 合并成二元组进行存储
    for(char c = 'a'; c <= 'z'; c++)
        if(cnt[c] != 0)
            G.push_back(pair<int, char>(cnt[c], c));
    
    sort(G.begin(), G.end()); // 按出现数量从小到大排序
    
    int n = s.size();
    if(G.back().first > (n + 1) / 2)
    {
        cout << "No\n";
        return;
    }
    cout << "Yes\n";
    
    for(int i = 1; i <= n; i += 2) // 先把奇数位置按顺序填满
    {
        ans[i] = G.back().second;
        if(--G.back().first == 0)
            G.pop_back();
    }
    for(int i = 2; i <= n; i += 2) // 再把偶数位置按顺序填满
    {
        ans[i] = G.back().second;
        if(--G.back().first == 0)
            G.pop_back();
    }
    
    for(int i = 1; i <= n; i++)
        cout << ans[i];
    cout << "\n";
}
int main()
{
    int T;
    cin >> T;
    while(T--)
        solve();
    return 0;
}