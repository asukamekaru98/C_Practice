#include<stdio.h>
#include<math.h>

int main()
{
    int i;
    double a, b, s, t, last;

    // �����l�̐ݒ�
    a = 1;                  // �����la
    b = 1 / sqrt(2.0);      // �����lb
    s = 1;                  // �����ls
    t = 4;                  // �����lt

    // ���C�����[�v: 3��̔����v�Z���s��
    for (i = 0; i < 3; i++) {
        last = a;                           // �O���a��ۑ�
        a = (a + b) / 2;                    // a�̍X�V: a��b�̕���
        b = sqrt(last * b);                 // b�̍X�V: �O���a��b�̐ς̕�����
        s -= t * (a - last) * (a - last);   // s�̍X�V: (a - last)^2��t���|����s���猸�Z
        t *= 2;                             // t�̍X�V: t��2�{�ɂ���

        // �v�Z���ʂ��o��: (a + b)^2 / s
        printf("%16.14f\n", (a + b) * (a + b) / s);
    }
}