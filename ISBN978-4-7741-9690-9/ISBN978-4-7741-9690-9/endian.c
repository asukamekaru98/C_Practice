#include<stdio.h>
#include<stdlib.h>

int main()
{
	int i = 1;

	// int�^�ϐ�i�̃A�h���X��char�^�|�C���^�ɃL���X�g���A���̒l���m�F���邱�ƂŃG���f�B�A���𔻒�
	if (*((char*)&i)) {
		// �ŏ��̃o�C�g����[���ł���΃��g���G���f�B�A��
		printf("���g���G���f�B�A��");
	}
	else if (*((char*)&i + (sizeof(int) - 1))) {
		// �Ō�̃o�C�g����[���ł���΃r�b�O�G���f�B�A��
		printf("�N�\�f�J�G���f�B�A��");
	}
	else {
		printf("�s��\n");
	}
}