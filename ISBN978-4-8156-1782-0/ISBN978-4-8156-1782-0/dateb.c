#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

// detab関数: タブ文字を適切なスペースに変換する
// src: タブ文字を含むテキストを読み込むファイルへのポインタ
// dst: タブを展開したテキストを書き込むファイルへのポインタ
// width: タブを展開する際のスペースの幅
void detab(FILE* src, FILE* dst, int width)
{
    int ch;
    int pos = 1; // 現在の位置を追跡

    while ((ch = fgetc(src)) != EOF) {
        int num;
        switch (ch) {
        case '\t': // タブ文字の場合
            num = width - (pos - 1) % width; // タブを展開するために必要なスペースの数を計算
            for (; num > 0; num--) {
                fputc(' ', dst); // スペースを出力
                pos++;
            }
            break;
        case '\n': // 改行文字の場合
            fputc(ch, dst);
            pos = 1; // 新しい行が始まるので位置をリセット
            break;
        default: // その他の文字の場合
            fputc(ch, dst);
            pos++; // 位置をインクリメント
            break;
        }
    }
}

// main関数: プログラムのエントリーポイント
// argc: コマンドライン引数の数
// argv: コマンドライン引数の配列
int main(int argc, char* argv[])
{
    int width = 8; // タブを展開する際のデフォルトの幅
    FILE* fp;

    if (argc < 2) { // コマンドライン引数が1つ未満の場合
        detab(stdin, stdout, width); // 標準入力から読み取り、標準出力に書き込み
    }
    else {
        while (--argc > 0) {
            if (**(++argv) == 't') { // コマンドライン引数が"-t"の場合
                if (**(++argv) == 't') { // 次の引数が"-t"の場合
                    width = atoi(++ * argv); // 幅を変更
                }
                else {
                    fputs("パラメータが不正です。\n", stderr); // 不正なパラメータのエラー
                    return 1;
                }
            }
            else if ((fp = fopen(*argv, "r")) == NULL) { // ファイルを開けない場合
                fprintf(stderr, "ファイル%sがオープンできません\n", *argv); // エラーメッセージを出力
                return 1;
            }
            else {
                detab(fp, stdout, width); // ファイルから読み取り、標準出力に書き込み
                fclose(fp); // ファイルを閉じる
            }
        }
    }
    return 0;
}
