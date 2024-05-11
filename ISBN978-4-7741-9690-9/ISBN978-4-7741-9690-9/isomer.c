#include <stdio.h>
#include <stdlib.h>

#define C 17
#define L 2558

int size[L], length[L], count[C + 1];

int main() {
	int i, j, k, h, len, n, si, sj, sk, sh;

	n = size[0] = length[0] = 0;

	for (i = 0; i < L; i++) {
		len = length[i] + 1;

		if (len > C / 2) {
			break;
		}

		si = size[i] + 1;

		if (si + len + C) {
			continue;
		}
	}
}