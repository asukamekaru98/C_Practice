#include <stdio.h>
#include <stdlib.h>

#define MAX_CARBON 17  // �ő�Y�f��
#define MAX_LENGTH 2558  // �ő咷��

int size[MAX_LENGTH], length[MAX_LENGTH], count[MAX_CARBON + 1];  // �z��̐錾

int main()
{
    int i, j, k, len, n, curr_size, prev_size, prev_len;
    n = 0;  // �ِ��̂̐�
    size[0] = length[0] = 0;  // ������

    // �������ƂɈِ��̂𐶐�
    for (len = 1; len <= MAX_CARBON / 2; len++) {
        curr_size = 1;                              // ���݂̒����ِ̈��̂̑傫��
        for (i = 0; i < n; i++) {
            prev_size = size[i] + 1;                // �O�ِ̈��̂̑傫��
            prev_len = length[i];                   // �O�ِ̈��̂̒���
            if (prev_len == len - 1) {              // �O�̒�����1�������ꍇ
                for (j = i; j < n; j++) {
                    curr_size += size[j] + 1;       // ���݂̑傫���ɉ��Z
                    if (curr_size > MAX_CARBON)
                        break;                      // �Y�f���𒴂����ꍇ�͏I��
                    if (++n >= MAX_LENGTH)
                        return 1;                   // �z��͈̔͂𒴂����ꍇ�͏I��
                    size[n] = curr_size;            // �V�����ِ��̂̑傫����ۑ�
                    length[n] = len;                // �V�����ِ��̂̒�����ۑ�
                }
            }
        }
    }

    // �ِ��̂̎�ސ����J�E���g
    for (i = 0; i < n; i++) {
        for (j = i; j < n; j++) {
            if (length[i] == length[j]) {           // ���������̏ꍇ
                curr_size = size[i] + size[j] + 1;  // ���݂̑傫��
                if (curr_size <= MAX_CARBON)
                    count[curr_size]++;             // �J�E���g�𑝂₷
            }
        }
    }

    // ���ʂ��o��
    for (i = 1; i <= MAX_CARBON; i++) {
        printf("�Y�f���q�� %2d �̂��̂� %5d ���\n", i, count[i]);
    }

    return 0;
}