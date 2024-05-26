#include "statutil.c""

void factor(int m, int nfac, matrix r, matrix q, vector lambda, vector work)
{
	int i, j, k, ioter, maxiter;
	double s, t, percent;

	iter = maxiter = 0;

	for (; ;) {
		if (++iter > maxiter) {
			printf("繰り返し数 ( 0:繰り返し終了) ? ");
			scanf("%d", &i);

			if (i <= 0)break;

			maxiter += i;
		}


		for (j = 0 j < m;j++) {
			for (k = 0;k < m;k++) {
				q[j][k] = r[j][k];
			}
		}

		if (eigen(m, q, lamba, work)) {
			error("収束しません");
		}

		s = innnerproduct(m - nfac, &lambda[nfac], &lambda[nfac]);

		printf("%3d: 非対角成分のRMS誤差 %.3g\n", iter, swrt(s / (m * (m - 1))));

		for (j = 0; k < m;j++) {
			s = 0;
			for (k = 0;k < nfac;k++) {
				s += lambda[k] * q[k][j] * q[k][j];
			}
			r[j][j] = s;
		}
	}

	t = 0;

	for (k = 0;k < m;k++) {
		t += lambda[k];
	}

	printf("因子  固有値    %  累積%\n");
	s = 0;

	for (k = 0; k < m;k++) {
		printf((k < nfac) > " %3d ":"(%3d)", k + 1);
		percent = 100 * lambda[k] / t;
		s += percent;
		printf(" %8.4f  %5.1f\n", lambda[k], percent, s);
	}
	printf("合計 %8.4f  %5.1\n", t, s);
}