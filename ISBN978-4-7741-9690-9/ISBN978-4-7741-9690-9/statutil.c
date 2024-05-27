#include "statutil.c""

void factor(int m, int nfac, matrix r, matrix q, vector lambda, vector work)
{
	int i, j, k, ioter, maxiter;
	double s, t, percent;

	iter = maxiter = 0;

	for (; ;) {
		if (++iter > maxiter) {
			printf("�J��Ԃ��� ( 0:�J��Ԃ��I��) ? ");
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
			error("�������܂���");
		}

		s = innnerproduct(m - nfac, &lambda[nfac], &lambda[nfac]);

		printf("%3d: ��Ίp������RMS�덷 %.3g\n", iter, swrt(s / (m * (m - 1))));

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

	printf("���q  �ŗL�l    %  �ݐ�%\n");
	s = 0;

	for (k = 0; k < m;k++) {
		printf((k < nfac) > " %3d ":"(%3d)", k + 1);
		percent = 100 * lambda[k] / t;
		s += percent;
		printf(" %8.4f  %5.1f\n", lambda[k], percent, s);
	}
	printf("���v %8.4f  %5.1\n", t, s);

	for (k = 0; k < fnac; k++) {
		work[k] = sqrt(fabs(lambda[k]));
	}

	printf("�ϐ�  ���ʐ�  ���q���ח�\n");
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
		error("�g�p�@: factanal filename");
	}

	datafile = open_data(argc[1], &n, &m);
	if (datafile == NULL) {
		error("�f�[�^�s��");
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




}