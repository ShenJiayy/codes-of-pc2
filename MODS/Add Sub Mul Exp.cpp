#include <string>
#include <cstring>
#include <iostream>
using namespace std;

struct big {
	int a[100005];
	int &operator [] (int x) { // return the number at {x}.
		if (x > 100000) throw "The parameter is incorrect: The address cannot be reached.";
		return a[x];
	}
	int size() { // return the size of this number.
		return a[0];
	}
	void clear() { // clean the number and reset this number.
		memset(a, 0, sizeof a);
		a[0] = 1;
	}
	void push(string s) { // in struct define operator = with string type.
		int l = s.size();
		for (int i = 1; i <= l; i ++)
			a[i] = s[l - i] - '0';
		a[0] = l;
	}
	void reset() {clear();} // the port of function "clear()".
	string getstr() { // return the number with string type.
		string res = "";
		for (int i = 1; i <= a[0]; i ++)
			res += char(a[i] + '0');
		return res;
	} 
	big(string _str) { // string input.
		reset();
		push(_str);
	} 
	big(int _num) {
		reset();
		push(to_string(_num));
	} // number input.
	big(long long _num) {
		reset();
		push(to_string(_num));
	} // big number input.
	big() { // null input.
		reset();
	}
	void put() { // output without endline or space.
		for (int i = a[0]; i >= 1; i --)
			cout << a[i];
	}
	void get() { // get the string (use "cin") and push the string to this number.
		string s;
		cin >> s;
		push(s);
	}
	void operator = (int n) { // number input.
		reset();
		push(to_string(n));
	}
	void operator = (long long n) { // big number input.
		reset();
		push(to_string(n));
	}
	void operator = (string s) { // string input.
		reset();
		push(s);
	}
	void operator = (const char* s) {  // basic string input.
		string tmp = s;
		reset();
		push(tmp);
	}
	void operator = (big c) {  // "big" type input.
		a[0] = c[0];
		for (int i = 1; i <= a[0]; i ++)
			a[i] = c[i];
	}
	void operator += (big b) { // add big.
		big c;
		c[0] = max(a[0], b[0]);
		for (int i = 1; i <= c[0]; i ++)
			c[i] = a[i] + b[i];
		for (int i = 1; i <= c[0]; i ++) {
			c[i + 1] += c[i] / 10;
			c[i] %= 10;
			if (c[c[0] + 1])
				c[0] ++;
		}
		a[0] = c[0];
		for (int i = 1; i <= a[0]; i ++)
			a[i] = c[i];
	}
	void operator += (int _b) { // add number.
		big b, c;
		b.reset();
		b.push(to_string(_b));
		c[0] = max(a[0], b[0]);
		for (int i = 1; i <= c[0]; i ++)
			c[i] = a[i] + b[i];
		for (int i = 1; i <= c[0]; i ++) {
			c[i + 1] += c[i] / 10;
			c[i] %= 10;
			if (c[c[0] + 1])
				c[0] ++;
		}
		a[0] = c[0];
		for (int i = 1; i <= a[0]; i ++)
			a[i] = c[i];
	}
	void operator -= (big b) { // div big (only big - small)
		big c;
		c[0] = max(a[0], b[0]);
		for (int i = 1; i <= c[0]; i ++)
			c[i] = a[i] - b[i];
		for (int i = 1; i <= c[0]; i ++)
			if (c[i] < 0)
				c[i] += 10, c[i + 1] --;
		while (c[c[0]] == 0 && c[0] > 1) c[0] --;
		a[0] = c[0];
		for (int i = 1; i <= a[0]; i ++)
			a[i] = c[i];
	}
	void operator -= (int _b) { // div number (only big - small).
		big b, c;
		b.reset();
		b.push(to_string(_b));
		c[0] = max(a[0], b[0]);
		for (int i = 1; i <= c[0]; i ++)
			c[i] = a[i] - b[i];
		for (int i = 1; i <= c[0]; i ++)
			if (c[i] < 0)
				c[i] += 10, c[i + 1] --;
		while (c[c[0]] == 0 && c[0] > 1) c[0] --;
		a[0] = c[0];
		for (int i = 1; i <= a[0]; i ++)
			a[i] = c[i];
	}
	void operator *= (int b) { // mul number.
		big c;
		c[0] = a[0];
		for (int i = 1; i <= c[0]; i ++)
			c[i] = a[i] * b;
		for (int i = 1; i <= c[0]; i ++) {
			c[i + 1] += c[i] / 10;
			c[i] %= 10;
			if (c[c[0] + 1])
				c[0] ++;
		}
		a[0] = c[0];
		for (int i = 1; i <= a[0]; i ++)
			a[i] = c[i];
	}
	void operator *= (big b) { // mul big.
		big c;
		c[0] = a[0] + b[0];
		for (int i = 1; i <= a[0]; i ++)
			for (int j = 1; j <= b[0]; j ++)
				c[i + j - 1] = a[i] * b[j];
		for (int i = 1; i <= c[0]; i ++) {
			c[i + 1] += c[i] / 10;
			c[i] %= 10;
			if (c[c[0] + 1])
				c[0] ++;
		}
		a[0] = c[0];
		for (int i = 1; i <= a[0]; i ++)
			a[i] = c[i];
	}
	void operator /= (int b) { // expt number.
		big c;
		c[0] = a[0];
		int r = 0;
		for (int i = c[0]; i >= 1; i --) {
			int t = r * 10 + a[i];
			c[i] = t / b;
			r = t % b;
		}
		while (c[c[0]] == 0 && c[0] > 1)
			c[0] --;
		a[0] = c[0];
		for (int i = 1; i <= a[0]; i ++)
			a[i] = c[i];
	}
};
big operator + (big a, big b) { // return a + b.
	big c;
	c[0] = max(a[0], b[0]);
	for (int i = 1; i <= c[0]; i ++)
		c[i] = a[i] + b[i];
	for (int i = 1; i <= c[0]; i ++) {
		c[i + 1] += c[i] / 10;
		c[i] %= 10;
		if (c[c[0] + 1])
			c[0] ++;
	}
	return c;
}
big operator - (big a, big b) { // return a - b.
	big c;
	c[0] = max(a[0], b[0]);
	for (int i = 1; i <= c[0]; i ++)
		c[i] = a[i] - b[i];
	for (int i = 1; i <= c[0]; i ++)
		if (c[i] < 0)
			c[i] += 10, c[i + 1] --;
	while (c[c[0]] == 0 && c[0] > 1) c[0] --;
	return c;
}
big operator * (big a, int b) { // return a * b (big * int).
	big c;
	c[0] = a[0];
	for (int i = 1; i <= c[0]; i ++)
		c[i] = a[i] * b;
	for (int i = 1; i <= c[0]; i ++) {
		c[i + 1] += c[i] / 10;
		c[i] %= 10;
		if (c[c[0] + 1])
			c[0] ++;
	}
	return c;
}
big operator * (int a, big b) { // return a * b (int * big).
	return b * a;
}
big operator * (big a, big b) { // return a * b (big * big).
	big c;
	c[0] = a[0] + b[0];
	for (int i = 1; i <= a[0]; i ++)
		for (int j = 1; j <= b[0]; j ++)
			c[i + j - 1] = a[i] * b[j];
	for (int i = 1; i <= c[0]; i ++) {
		c[i + 1] += c[i] / 10;
		c[i] %= 10;
		if (c[c[0] + 1])
			c[0] ++;
	}
	return c;
}
big operator / (big a, int b) { // return a / b (big / int).
	big c;
	c[0] = a[0];
	int r = 0;
	for (int i = c[0]; i >= 1; i --) {
		int t = r * 10 + a[i];
		c[i] = t / b;
		r = t % b;
	}
	while (c[c[0]] == 0 && c[0] > 1)
		c[0] --;
	return c;
} //将a/b的结果写入c
bool operator < (big a, big b) {
	if (a[0] != b[0]) return a[0] < b[0];
	for (int i = a[0]; i >= 1; i --)
		if (a[i] != b[i])
			return a[i] < b[i];
	return 0;
}
bool operator == (big a, big b) {
	if (a[0] != b[0]) return 0;
	for (int i = a[0]; i >= 1; i --)
		if (a[i] != b[i])
			return 0;
	return 1;
}
bool operator > (big a, big b) {
	if (a[0] != b[0]) return a[0] > b[0];
	for (int i = a[0]; i >= 1; i --)
		if (a[i] != b[i])
			return a[i] > b[i];
	return 0;
}

typedef long long ll;

ll to(big s, ll k) {
	ll ans = 0;
	for (int i = 0; i < s.size(); i ++) {
		if (s[i] <= '9')
			ans = ans * k + s[i] - '0';
		else
			ans = ans * k + s[i] - 'A' + 10;
	}
	return ans;
}
namespace Private {
	char turn(int x) {
		if (x > 9) return x - 10 + 'A';
		return x + '0';
	}
}
string to(ll n, int k) {
	string ans = "";
	while (n) {
		ans = Private::turn(n % k) + ans;
		n /= k;
	}
	return ans;
}

// user define function and struct type (or array, int number)

int main() {
	
	return 0;
}
