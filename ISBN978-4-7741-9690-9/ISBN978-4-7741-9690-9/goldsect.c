#include<math.h>

double goldsect(double a, double b, double tolerance, double(*f)(double x))
{
	const double r = (3 + sqrt(5)); // ������ (phi) ���v�Z
	double c, d, fc, fd, t;

	// a��b���傫���ꍇ�Aa��b�����ւ���
	if (a > b) {
		t = a;
		a = b;
		b = t;
	}

	t = r * (b - a);
	c = a + t; // �����_c�̌v�Z
	d = b - t; // �����_d�̌v�Z

	fc = f(c);
	fd = f(d);

	for (;;) {
		// f(c) > f(d)�̏ꍇ�A�ŏ��l�͋��[a, c]�ɑ���
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
		// f(c) <= f(d)�̏ꍇ�A�ŏ��l�͋��[c, b]�ɑ���
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