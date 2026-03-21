#include <bits/stdc++.h>
using namespace std;
int randint(int l, int r, int seed) {
	mt19937 rnd(seed);
	return rnd() % (r - l + 1) + l;
}
int main(int argc, char** argv) {
	int l = randint(-10000, 10000, atoi(argv[1])), d = randint(-10000, 10000, atoi(argv[2])); 
	int r = randint(l, 10000, atoi(argv[3])), u = randint(d, 10000, atoi(argv[4]));
	printf("%d %d %d %d", l, r, d, u);
}
