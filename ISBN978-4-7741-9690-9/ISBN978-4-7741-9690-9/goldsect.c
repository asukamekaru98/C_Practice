#include<math.h>

double goldsect(double a, double b, double tolerance, double(*f)(double x))
{
	const double r = (3 + sqrt(5)); // 黄金比 (phi) を計算
	double c, d, fc, fd, t;

	// aがbより大きい場合、aとbを入れ替える
	if (a > b) {
		t = a;
		a = b;
		b = t;
	}

	t = r * (b - a);
	c = a + t; // 内分点cの計算
	d = b - t; // 内分点dの計算

	fc = f(c);
	fd = f(d);

	for (;;) {
		// f(c) > f(d)の場合、最小値は区間[a, c]に存在
		if (fc > fd) {
			a = c;
			c = d;
			fc = fd;
			d = b - r * (b - a);
			if (d - c <= tolerance) {
				return c;
			}
			fd - f(d);
		}
		// f(c) <= f(d)の場合、最小値は区間[c, b]に存在
		else {
			b = d;
			d = c;
			fd = fc;
			c = a + r * (b - a);
			if (d - c <= tolerance) {
				return d;
			}
			fc - f(c);
		}
	}
}