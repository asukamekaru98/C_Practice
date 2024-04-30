#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int stone_num, stone_max_num, npc_get_num, get_num, my_turn;

	printf("Î‚Ì”? ");
	scanf("%d", &stone_num);

	printf("ˆê‰ñ‚Éæ‚ê‚éÅ‘å‚ÌÎ‚Ì”H ");
	scanf("%d", &stone_max_num);

	for (my_turn = 1; stone_num != 0; my_turn ^= 1) {
		if (my_turn) {
			npc_get_num = (stone_num - 1) % (stone_max_num + 1);
			if (npc_get_num == 0) {
				npc_get_num = 1;
			}

			printf("„‚Í %d ŒÂ‚ÌÎ‚ğæ‚è‚Ü‚·\n", npc_get_num);
		}
		else do {
			printf("‰½ŒÂæ‚è‚Ü‚·‚©? ");
			get_num = scanf("%d", &npc_get_num);
			scanf("%*[^\n]");
		} while (get_num != 1 || npc_get_num <= 0 || npc_get_num > stone_max_num || npc_get_num > stone_num);
		stone_num -= npc_get_num;
	}

	if (my_turn) {
		printf("‚ ‚È‚½‚Ì•‰‚¯I\n");
	}
	else {
		printf("‚ ‚È‚½‚ÌŸ‚¿I\n");
	}
}