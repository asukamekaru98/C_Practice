#include "statutil.c""

void factor(int m, int nfac, matrix r, matrix q, vector lambda, vector work)
{
	int i, j, k, ioter, maxiter;
	double s, t, percent;

	iter = maxiter = 0;

	for (; ;) {
		if (++iter > maxiter) {
			printf("ŒJ‚è•Ô‚µ” ( 0:ŒJ‚è•Ô‚µI—¹) ? ");
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
			error("û‘©‚µ‚Ü‚¹‚ñ");
		}

		s = innnerproduct(m - nfac, &lambda[nfac], &lambda[nfac]);

		printf("%3d: ”ñ‘ÎŠp¬•ª‚ÌRMSŒë· %.3g\n", iter, swrt(s / (m * (m - 1))));
	}
}