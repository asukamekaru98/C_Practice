#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#define N 3
int boy[N + 1], girl[N + 1][N + 1], position[N + 1], rank[N + 1][N + 1];

int main(void)
{
	int b, g, r, s, t;

	//�e�������j���̍D�݂������N�t��
	for (g = 1; g <= N; g++) {
		for (r = 1; r <= N; r++) {
			scanf("%d", &b);
			rank[g][b] = r;	
		}
		boy[g] = 0;			//�������H
		rank[g][0] = N + 1;	//
	}

	//�e�j���������̍D�݂������N�t��
	for (b = 1; b <= N; b++) {
		for (r = 1; r <= N; r++) {
			scanf("%d", &girl[b][r]);
			position[b] = 0;
		}
	}
	
	// ���茋���̌v�Z
	for (b = 1; b <= N; b++) {
		s = b;
		while (s != 0) {
			g = girl[s][++position[s]]; // ���� s �����Ƀv���|�[�Y����j���̔ԍ����擾
			if (rank[g][s] < rank[g][boy[g]]) { // ���� s ���j�� g ��I�D���Ă���A���j�� g ������ s �����݂̍���҂����I�D����ꍇ
				t = boy[g]; // �j�� g �̌��݂̍���҂��ꎞ�I�ɕۑ�
				boy[g] = s; // �j�� g �͏��� s �ƍ���
				s = t; // ���� t �Ƀv���|�[�Y����it �͒j�� g �̈ȑO�̍���ҁj
			}
		}
	}

	for (g = 1; g <= N; g++) {
		printf("�� %d - �j %d\n", g, boy[g]);	//�����N���o��
	}
	return 0;
}