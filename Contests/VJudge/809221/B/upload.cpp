#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5, V = 100;
int a[N + 5], b[N + 5], c[N + 5];
/*
Harekaze
创建时间：2025-10-21 19:37
查看文章
UPD on 2026/04/07：修正错误。
1. 题目分析
大概是普及吧。
首先明确一下题目，我们设 A 为只有 a 相等的对数，B 为只有 b 相等的对数，C 为只有 c 相等的对数。
那么答案显然为 S=A+B+C。
我们来看看 A 如何计算，B 和 C 同理。
我们令 A' 表示 A 相等的对数，AB 表示 a,b 均相等的对数，AC 表示 a,c 均相等的对数，BC 表示 b,c 均相等的对数，ABC 表示 a,b,c 均相等的对数。
考虑容斥，A=A'−AB−AC+ABC。
同理可得，B=B'−AB−BC+ABC。
于是也有，C=C'−AC−BC+ABC。
那么 S=A'+B'+C'−2×(AB+AC+BC)+3×ABC。
*/
int hs(int a, int b) { return (a - 1) * 100 + (b - 1) * 1; }
int hs(int a, int b, int c) { return (a - 1) * 10000 + (b - 1) * 100 + (c - 1) * 1; }
vector<int> a1[V + 5], b1[V + 5], c1[V + 5], ab1[V * 101 + 5], ac1[V * 101 + 5], bc1[V * 101 + 5], abc1[V * 10101 + 5];
signed main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i ++)
		cin >> a[i] >> b[i] >> c[i];
	for (int i = 1; i <= n; i ++) {
		a1[a[i]].push_back(i), 
		b1[b[i]].push_back(i), 
		c1[c[i]].push_back(i),
		ab1[hs(a[i], b[i])].push_back(i),
		ac1[hs(a[i], c[i])].push_back(i),
		bc1[hs(b[i], c[i])].push_back(i),
		abc1[hs(a[i], b[i], c[i])].push_back(i);
	}
	int aa = 0, bb = 0, cc = 0, ab = 0, ac = 0, bc = 0, abc = 0;
	for (int i = 0; i <= V; i ++) {
		aa += a1[i].size() * (a1[i].size() - 1) / 2,
		bb += b1[i].size() * (b1[i].size() - 1) / 2,
		cc += c1[i].size() * (c1[i].size() - 1) / 2;
	}
	for (int i = 0; i <= V * 101; i ++) {
		ab += ab1[i].size() * (ab1[i].size() - 1) / 2,
		ac += ac1[i].size() * (ac1[i].size() - 1) / 2,
		bc += bc1[i].size() * (bc1[i].size() - 1) / 2;
	}
	for (int i = 0; i <= V * 10101; i ++)
		abc += abc1[i].size() * (abc1[i].size() - 1) / 2;
	cout << aa + bb + cc - 2 * (ab + bc + ac) + 3 * abc;
	return 0;
}
