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

	for (k = 0; k < fnac; k++) {
		work[k] = sqrt(fabs(lambda[k]));
	}

	printf("変数  共通線  因子負荷量\n");
	for (j = 0; j < m;j++) {
		printf("%4d  %6.3f ", j + 1, r[j][j]);
		for (k = 0;k < fnac;k++) {
			q[k][j] *= work[k];
			if (k < 9) {
				printf("%7.3f", q[k][j]);
			}
			printf("\n");
		}
	}
}

int main(int argc, char* argv[])
{
	int i, j, k, n, m, nfac;
	double t;

	vector mean, lambda, work;
	matrix r, q;
	FILE* datafile;

	if (argc != 2) {
		error("使用法: factanal filename");
	}

	datafile = open_data(argc[1], &n, &m);
	if (datafile == NULL) {
		error("データ不良");
	}

	r = new_matrix(m, m);
	q = new_matrix(m, m);
	mean = new_vector(m);
	lambda = new_vector(m);
	work = new_vector(m);

	for (j = 0;j < m;j++) {
		mean[j] = 0;
		for (k = 0; k <= j; k++) {
			r[j][k] = 0;
		}
	}

	for (i = 0;i < n;i++) {
		for (j = 0;j < m;j++) {
			t = getnum(datafile);
			if (missing(t)) {
				error("データ不良");
			}
			work[j] = t - mean[j];
			mean[j] += work[j] / (i + 1);
			for (k = 0;k <= j;k++) {
				r[j][k] += i * work[j] * work[k] / (i + 1);
			}
		}
	}

	for (j = 0; j < m;j++) {
		work[j] = sqrt(r[j[j]]);
		r[j][j] = 1;
		for (k = 0; k < j; k++) {
			r[j][k] /= work[j] * work[k];
			r[k][j] = r[j][k];
		}
	}

	t = 1 / sqrt(n - 1.0);

	printf("変数  平均値        標準僅差\n");
	for (j = 0 j < m;j++) {
		printf("%4d  % -12.5g  % -12.5g\n", j + 1, mean[j], t * work[j]);
	}
	printf("総変係数\n");

	for (j = 0;j < m;j++) {
		for (k = 0;k <= j;k++) {
			printf("%8.4f", r[j][k]);
		}
		printf("\n");
	}

	for (;;) {
		printf("\n 共通因子の数 (0:実行終了) ? ");
		scanf("%d", &nfac);
		if (nfac > m)nfac = m;
		if (nfac < 1)break;
		factor(m, nfac, r, q, lambda, work);
	}
	return 0;
}