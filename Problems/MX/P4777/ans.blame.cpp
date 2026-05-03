// P4777 【模板】扩展中国剩余定理（EXCRT）
int exgcd(int a, int b, int &x, int &y)
{
	if(b == 0)
	{
		x = 1, y = 0;
		return a;
	}
	
	int x1, y1, d;
	d = exgcd(b, a%b, x1, y1);
	x = y1, y = x1 - a/b*y1;
	return d;
}

int EXCRT(int m[], int r[], int n)
{
	int m1 = m[1], r1 = r[1];
	for(int i = 2; i <= n; i ++)
	{
		int p, q;
		int d = exgcd(m1, m[i], p, q);
		if( (r[i] - r1) % d > 0)
			return -1;
		p = p * (r[i] - r1) / d; //特解
    	p = (p % (m[i]/d) + m[i]/d) % (m[i]/d); //求出 p 在模 m[i]/d 意义下的最小正整数
		r1 = m1 * p + r1, m1 = m1 * m[i] / d;
	}
	return (r1 % m1 + m1) % m1;
}
