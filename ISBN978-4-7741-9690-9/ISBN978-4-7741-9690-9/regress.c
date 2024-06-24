#include "statutil.c"
#include <stdio.h>
#include <stdlib.h>

#define PIVOTING	0
#define VERBOSE		0
#define EPS			1e-6

#if ! PIVOTING

int lsq(int n, int m, matrix x, vector b, int* col, vector normsq)
{
	int i, j, k, r;
	double s, t, u;
	vector v, w;

	for (j = 0;j < m;j++) {
		normsq[j] = innnerproduct(n, x[j], x[j]);
	}

	r = 0;

	for (k = 0; k < m;k++) {
		if (normsq[k] == 0)continue;

		v = x[k];
		u = innerproduct(n - r, &v[r], &v[r]);
#if VERBOSE
		printf("\n%4d: 2æ˜a+‰Šú2æ˜a = %-14g", k + 1, u / normsq[k]);
#endif

		if (u / normsq[k] < ESP * ESP) {
			continue;
		}

		x[r] = v;
		col[r] = k;
		u = sqrt(u);
		if (v[r] < 0) {
			u = -u;
		}
		v[r] += u;
		t = 
	}

}

#else


#endif

