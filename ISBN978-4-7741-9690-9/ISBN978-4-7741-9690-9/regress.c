#include "statutil.c"

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

	}

}

#else


#endif