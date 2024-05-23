#include <stdio.h>
#include <stdlib.h>

#define MAX_CARBON 17  // 最大炭素数
#define MAX_LENGTH 2558  // 最大長さ

int size[MAX_LENGTH], length[MAX_LENGTH], count[MAX_CARBON + 1];  // 配列の宣言

int main()
{
    int i, j, k, len, n, curr_size, prev_size, prev_len;
    n = 0;  // 異性体の数
    size[0] = length[0] = 0;  // 初期化

    // 長さごとに異性体を生成
    for (len = 1; len <= MAX_CARBON / 2; len++) {
        curr_size = 1;                              // 現在の長さの異性体の大きさ
        for (i = 0; i < n; i++) {
            prev_size = size[i] + 1;                // 前の異性体の大きさ
            prev_len = length[i];                   // 前の異性体の長さ
            if (prev_len == len - 1) {              // 前の長さが1小さい場合
                for (j = i; j < n; j++) {
                    curr_size += size[j] + 1;       // 現在の大きさに加算
                    if (curr_size > MAX_CARBON)
                        break;                      // 炭素数を超えた場合は終了
                    if (++n >= MAX_LENGTH)
                        return 1;                   // 配列の範囲を超えた場合は終了
                    size[n] = curr_size;            // 新しい異性体の大きさを保存
                    length[n] = len;                // 新しい異性体の長さを保存
                }
            }
        }
    }

    // 異性体の種類数をカウント
    for (i = 0; i < n; i++) {
        for (j = i; j < n; j++) {
            if (length[i] == length[j]) {           // 同じ長さの場合
                curr_size = size[i] + size[j] + 1;  // 現在の大きさ
                if (curr_size <= MAX_CARBON)
                    count[curr_size]++;             // カウントを増やす
            }
        }
    }

    // 結果を出力
    for (i = 1; i <= MAX_CARBON; i++) {
        printf("炭素原子が %2d 個のものは %5d 種類\n", i, count[i]);
    }

    return 0;
}