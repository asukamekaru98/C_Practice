#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

// detab�֐�: �^�u������K�؂ȃX�y�[�X�ɕϊ�����
// src: �^�u�������܂ރe�L�X�g��ǂݍ��ރt�@�C���ւ̃|�C���^
// dst: �^�u��W�J�����e�L�X�g���������ރt�@�C���ւ̃|�C���^
// width: �^�u��W�J����ۂ̃X�y�[�X�̕�
void detab(FILE* src, FILE* dst, int width)
{
    int ch;
    int pos = 1; // ���݂̈ʒu��ǐ�

    while ((ch = fgetc(src)) != EOF) {
        int num;
        switch (ch) {
        case '\t': // �^�u�����̏ꍇ
            num = width - (pos - 1) % width; // �^�u��W�J���邽�߂ɕK�v�ȃX�y�[�X�̐����v�Z
            for (; num > 0; num--) {
                fputc(' ', dst); // �X�y�[�X���o��
                pos++;
            }
            break;
        case '\n': // ���s�����̏ꍇ
            fputc(ch, dst);
            pos = 1; // �V�����s���n�܂�̂ňʒu�����Z�b�g
            break;
        default: // ���̑��̕����̏ꍇ
            fputc(ch, dst);
            pos++; // �ʒu���C���N�������g
            break;
        }
    }
}

// main�֐�: �v���O�����̃G���g���[�|�C���g
// argc: �R�}���h���C�������̐�
// argv: �R�}���h���C�������̔z��
int main(int argc, char* argv[])
{
    int width = 8; // �^�u��W�J����ۂ̃f�t�H���g�̕�
    FILE* fp;

    if (argc < 2) { // �R�}���h���C��������1�����̏ꍇ
        detab(stdin, stdout, width); // �W�����͂���ǂݎ��A�W���o�͂ɏ�������
    }
    else {
        while (--argc > 0) {
            if (**(++argv) == 't') { // �R�}���h���C��������"-t"�̏ꍇ
                if (**(++argv) == 't') { // ���̈�����"-t"�̏ꍇ
                    width = atoi(++ * argv); // ����ύX
                }
                else {
                    fputs("�p�����[�^���s���ł��B\n", stderr); // �s���ȃp�����[�^�̃G���[
                    return 1;
                }
            }
            else if ((fp = fopen(*argv, "r")) == NULL) { // �t�@�C�����J���Ȃ��ꍇ
                fprintf(stderr, "�t�@�C��%s���I�[�v���ł��܂���\n", *argv); // �G���[���b�Z�[�W���o��
                return 1;
            }
            else {
                detab(fp, stdout, width); // �t�@�C������ǂݎ��A�W���o�͂ɏ�������
                fclose(fp); // �t�@�C�������
            }
        }
    }
    return 0;
}
