#include <bits/stdc++.h>
using namespace std;

int n, posA, posB, A[200005];

void Main_1() {
	for(int i = 1; i <= n; i++) {
		scanf("%d", &A[i]);
		for(int j = i - 1; j >= 1; j--) {
			if(A[j] != A[i]) continue;
			for(int k = j + 1; k <= i - 1; k++) A[k] = A[i];
			break;
		}
	}
	for(int i = 1; i <= n; i++) printf("%d\n", A[i]);
}

void Main_2() {
	for(int i = 1; i <= n; i++) {
		scanf("%d", &A[i]);
		if(A[i] == 1) {
			if(posA < posB && posA) posB = 0;
			posA = i;
		}
		if(A[i] == 2) {
			if(posB < posA && posB) posA = 0;
			posB = i;
		}
	}
	if(posA <= posB) {
		for(int i = 1; i <= posA; i++) printf("1\n");
		for(int i = posA + 1; i <= posB; i++) printf("2\n");
	}
	if(posB < posA) {
		for(int i = 1; i <= posB; i++) printf("2\n");
		for(int i = posB + 1; i <= posA; i++) printf("1\n");
	}
}

int main() {
	freopen("stone.in", "r", stdin);
	freopen("stone.out", "w", stdout);
	scanf("%d", &n);
	if(n <= 2000) { Main_1();  return 0; }
	Main_2();  return 0;
}
