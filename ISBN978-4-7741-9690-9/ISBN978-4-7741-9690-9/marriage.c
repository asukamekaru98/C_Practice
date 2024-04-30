#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#define N 3
int boy[N + 1], girl[N + 1][N + 1], position[N + 1], rank[N + 1][N + 1];

int main(void)
{
	int b, g, r, s, t;

	//各女性が男性の好みをランク付け
	for (g = 1; g <= N; g++) {
		for (r = 1; r <= N; r++) {
			scanf("%d", &b);
			rank[g][b] = r;	
		}
		boy[g] = 0;			//初期化？
		rank[g][0] = N + 1;	//
	}

	//各男性が女性の好みをランク付け
	for (b = 1; b <= N; b++) {
		for (r = 1; r <= N; r++) {
			scanf("%d", &girl[b][r]);
			position[b] = 0;
		}
	}
	
	// 安定結婚の計算
	for (b = 1; b <= N; b++) {
		s = b;
		while (s != 0) {
			g = girl[s][++position[s]]; // 女性 s が次にプロポーズする男性の番号を取得
			if (rank[g][s] < rank[g][boy[g]]) { // 女性 s が男性 g を選好しており、かつ男性 g が女性 s を現在の婚約者よりも選好する場合
				t = boy[g]; // 男性 g の現在の婚約者を一時的に保存
				boy[g] = s; // 男性 g は女性 s と婚約
				s = t; // 女性 t にプロポーズする（t は男性 g の以前の婚約者）
			}
		}
	}

	for (g = 1; g <= N; g++) {
		printf("女 %d - 男 %d\n", g, boy[g]);	//ランクを出力
	}
	return 0;
}